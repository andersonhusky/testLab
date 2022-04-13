#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
bool isRotationMatrix(const cv::Mat &R){
    cv::Mat Rt;
    transpose(R,Rt);
    cv::Mat shouldBeIdentity = Rt*R;
    cv::Mat I = cv::Mat::eye(3,3,shouldBeIdentity.type());
    return norm(I,shouldBeIdentity) < 1e-6;
}

// 一个旋转矩阵可能对应好几个欧拉角
cv::Mat rotm2euler(const cv::Mat &R){
    assert(isRotationMatrix(R));
    float sy = sqrt(R.at<double>(0,0) * R.at<double>(0,0) +  R.at<double>(1,0) * R.at<double>(1,0) );
    bool singular = sy < 1e-6;
    float x, y, z;
    if (!singular)
    {
        x = atan2(R.at<double>(2,1) , R.at<double>(2,2));
        y = atan2(-R.at<double>(2,0), sy);
        z = atan2(R.at<double>(1,0), R.at<double>(0,0));
    }
    else
    {
        x = atan2(-R.at<double>(1,2), R.at<double>(1,1));
        y = atan2(-R.at<double>(2,0), sy);
        z = 0;
    }
    cv::Mat res = (cv::Mat_<double>(1,3) << x, y, z);
    return res;
}

cv::Mat euler2rotm(const cv::Mat &euler){
    double x=euler.at<double>(0);
    double y=euler.at<double>(1);
    double z=euler.at<double>(2);
    cv::Mat res(3, 3, CV_64FC1);
    res.at<double>(0, 0)=cos(y)*cos(z);
    res.at<double>(0, 1)=sin(x)*sin(y)*cos(z)-cos(x)*sin(z);
    res.at<double>(0, 2)=cos(x)*sin(y)*cos(z)+sin(x)*sin(z);

    res.at<double>(1, 0)=cos(y)*sin(z);
    res.at<double>(1, 1)=sin(x)*sin(y)*sin(z)+cos(x)*cos(z);
    res.at<double>(1, 2)=cos(x)*sin(y)*sin(z)-sin(x)*cos(z);

    res.at<double>(2, 0)=-sin(y);
    res.at<double>(2, 1)=sin(x)*cos(y);
    res.at<double>(2, 2)=cos(x)*cos(y);
    return res;
}

int main(){
    cv::Mat euler(1, 3, CV_64FC1);
    cin >> euler.at<double>(0);
    cin >> euler.at<double>(1);
    cin >> euler.at<double>(2);
    std::cout << euler << std::endl;
    cv::Mat R=euler2rotm(euler);
    std::cout << R << endl;
    euler = rotm2euler(R);
    std::cout << euler << endl;
    R = euler2rotm(euler);
    std::cout << R << std::endl;
    return 0;
}
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
constexpr double PI = 3.1415926;
bool isRotationMatrix(const cv::Mat &R){
    cv::Mat Rt;
    transpose(R,Rt);
    cv::Mat shouldBeIdentity = Rt*R;
    cv::Mat I = cv::Mat::eye(3,3,shouldBeIdentity.type());
    return norm(I,shouldBeIdentity) < 1e-6;
}

cv::Mat angle2rotm(const cv::Mat &axis, double angle){
    cv::Mat res;
    double a = angle*PI/180.0;
    double cosa = cosf64(a), sina = sinf64(a);
    cv::Mat I = cv::Mat::eye(3, 3, CV_64FC1);
    double AXIS;
    cv::Mat axis_(1, 3, CV_64FC1);
    for(int i=0; i<3; i++)  AXIS += axis.at<double>(0, i)*axis.at<double>(0, i);
    for(int i=0; i<3; i++)  axis_.at<double>(0, i) = axis.at<double>(0, i)/AXIS;
    cv::Mat axishat = (cv::Mat_<double>(3, 3)
                 << 0, -axis.at<double>(0, 2), axis.at<double>(0, 1),
                    axis.at<double>(0, 2), 0, -axis.at<double>(0, 0),
                    -axis.at<double>(0, 1), axis.at<double>(0, 0), 0);
    return I+(axishat*axishat)*(1-cosa)+sina*axishat;
    // return cosa*I + (1-cosa)*(axis_.t()*axis_) + sina*axishat;
}

cv::Mat rotm2angle(const cv::Mat &R, double& angle){
    assert(isRotationMatrix(R));
    angle = acos((cv::trace(R).val[0]-1.0)/2);
    double sina = sinf64(angle);
    cv::Mat res = (cv::Mat_<double>(1,3) << 
                                (R.at<double>(2, 1)-R.at<double>(1, 2))/2/sina,
                                (R.at<double>(0, 2)-R.at<double>(2, 0))/2/sina,
                                (R.at<double>(1, 0)-R.at<double>(0, 1))/2/sina);
    angle = angle/PI*180.0;
    return res;
}

int main(){
    cv::Mat axis = (cv::Mat_<double>(1, 3) << 0, 0, 1);
    double angle = 45;
    cout << axis << ", " << angle << endl;
    cv::Mat R = angle2rotm(axis, angle);
    cout << R << endl;
    double angle2=0.0;
    cv::Mat tmp = rotm2angle(R, angle2);
    cout << tmp << ", " << angle2 << endl;
    return 0;
}
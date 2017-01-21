#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<cstdio>

using namespace cv;
using namespace std;

int main()
{
	bool satisfied;
	char choice;
	Mat frame;
	VideoCapture cap(0);
	if(!cap.open(0))
	{
		cout << "Couldn't find a camera.";
		return -1;
	}
	do
	{
		while(true)
			{
				cap >> frame;
				imshow("Output", frame);
				if(cvWaitKey(1)==27)
					break;
			}
		namedWindow("Output",WINDOW_AUTOSIZE);
		imshow("Output", frame);
		cout << "Are you satisfied ?";
		cin >> choice;
		satisfied = choice=='y' ? false : true;
	}while(satisfied);
	//cvtColor(frame, frame,CV_BGR2GRAY);
	imwrite("Your Picture.jpg", frame);
	return 0;
}

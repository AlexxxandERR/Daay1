#include "opencv2\opencv.hpp" 
#include <iostream> 

using namespace std;
using namespace cv;

int main(int, char**)
{
	setlocale(LC_ALL, "russian");
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cout << "Невозможно открыть камеру" << endl;
		cin.get();
		return -1;
	}
	String window_name = "Первое видео";
	namedWindow(window_name, WINDOW_NORMAL);
	while (true)
	{
		Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false) {
			cout << "Конец видео" << endl;
			break;
		}
			imshow(window_name, frame);
		if (waitKey(10) == 27)
		{
			cout << "Нажат Escape. Выход..." << endl;
			break;
		}

	}
	return 0;
}
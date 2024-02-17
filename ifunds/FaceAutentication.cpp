
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main() {
	int faceCount = 0;
	VideoCapture video(0);
	//This line initializes a VideoCapture object named video to capture video frames.
	//The argument 0 typically represents the default camera, though it can be replaced with the index of the desired camera.

	CascadeClassifier facedetect; // Cascade classifiers are trained using several postive images and arbitrary
	//negative images. It's like making a class , I named it, faceDetect according to my use.
	// It's loaded with a pre-trained XML file containing the parameters of the Haar cascade classifier trained for frontal face detection.

	Mat img; //A Mat object named img is declared to store each frame captured from the video feed.

	facedetect.load("haarcascade_frontalface_default.xml");

	while (true) {
		video.read(img);
		vector<Rect> faces;

		facedetect.detectMultiScale(img, faces, 1.3, 5);
		//The detectMultiScale method of the facedetect object is called to detect faces in the current frame (img).
		// The detected faces are stored in the faces vector. The parameters 1.3 and 5 represent the scale factor and minimum neighbors respectively.

		cout << faces.size() << endl;

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
			rectangle(img, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED);
			putText(img, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
		}

		faceCount += faces.size();


		imshow("Frame", img);
		waitKey(1);

		if (waitKey(1) == 27) { // Press ESC to exit the loop
			break;
		}


	}
	cout << "Face is detected , This person is a human ! Verification Complete" << faceCount;
}

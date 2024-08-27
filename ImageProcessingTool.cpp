#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load an image from file
    Mat image = imread("input.jpg", IMREAD_COLOR); // Change "input.jpg" to your image file

    // Check if the image was loaded successfully
    if (image.empty()) {
        cerr << "Error loading image!" << endl;
        return -1;
    }

    // Convert the image to grayscale
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    // Apply Gaussian blur to the grayscale image
    Mat blurredImage;
    GaussianBlur(grayImage, blurredImage, Size(15, 15), 0);

    // Save the resulting image
    imwrite("output_blurred.jpg", blurredImage);

    // Display the images
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", image);

    namedWindow("Gray Image", WINDOW_AUTOSIZE);
    imshow("Gray Image", grayImage);

    namedWindow("Blurred Image", WINDOW_AUTOSIZE);
    imshow("Blurred Image", blurredImage);

    // Wait until a key is pressed
    waitKey(0);

    return 0;
}
+9-0989

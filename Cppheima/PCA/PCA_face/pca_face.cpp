#include "funset.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <opencv2/opencv.hpp>

int ORLFacestoImage()
{
	const std::string path{ "E:/GitCode/NN_Test/data/database/ORL_Faces/" };
	cv::Mat dst;
	int height, width;

	for (int i = 1; i <= 40; ++i) {
		std::string directory = path + "s" + std::to_string(i) + "/";

		for (int j = 1; j <= 10; ++j) {
			std::string image_name = directory + std::to_string(j) + ".pgm";
			cv::Mat mat = cv::imread(image_name, 0);
			if (!mat.data) {
				fprintf(stderr, "read image fail: %s\n", image_name.c_str());
			}

			//std::string save_image_name = directory + std::to_string(j) + ".png";
			//cv::imwrite(save_image_name, mat);

			if (i == 1 && j == 1) {
				height = mat.rows;
				width = mat.cols;
				dst = cv::Mat(height * 20, width * 20, CV_8UC1);
			}

			int y_start = (i - 1) / 2 * height;
			int y_end = y_start + height;
			int x_start = (i - 1) % 2 * 10 * width + (j - 1) * width;
			int x_end = x_start + width;
			cv::Mat copy = dst(cv::Range(y_start, y_end), cv::Range(x_start, x_end));
			mat.copyTo(copy);
		}
	}

	int new_width = 750;
	float factor = dst.cols * 1.f / new_width;
	int new_height = dst.rows / factor;
	cv::resize(dst, dst, cv::Size(new_width, new_height));
	cv::imwrite("E:/GitCode/NN_Test/data/orl_faces_dataset.png", dst);

	return 0;
}
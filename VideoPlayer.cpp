// PlayVideoFileCpp.sln
// main.cpp

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
   
int main(void) {

    cv::VideoCapture capVideo;

    cv::Mat imgFrame;

    capVideo.open("Speed.mp4");

    if (!capVideo.isOpened()) {                                                 
        std::cout << "\nerror reading video file" << std::endl << std::endl;     
        getc;                   
    }

    if (capVideo.get(CV_CAP_PROP_FRAME_COUNT) < 1) {
        std::cout << "\nerror: video file must have at least one frame";
        getc;
        return(0);
    }

    capVideo.read(imgFrame);

    char chCheckForEscKey = 0;

    while (capVideo.isOpened() && chCheckForEscKey != 27) {

        cv::imshow("imgFrame", imgFrame);

                // now we prepare for the next iteration

        if ((capVideo.get(CV_CAP_PROP_POS_FRAMES) + 1) < capVideo.get(CV_CAP_PROP_FRAME_COUNT)) {       // if there is at least one more frame
            capVideo.read(imgFrame);                            // read it
        }
        else {                                                  // else
            std::cout << "end of video\n";                      // show end of video message
            break;                                              // and jump out of while loop
        }

        chCheckForEscKey = cv::waitKey(1);      // get key press in case user pressed esc

    }

    if (chCheckForEscKey != 27) {               // if the user did not press esc (i.e. we reached the end of the video)
        cv::waitKey(0);                         // hold the windows open to allow the "end of video" message to show
    }
        // note that if the user did press esc, we don't need to hold the windows open, we can simply let the program end which will close the windows

    return(0);
}









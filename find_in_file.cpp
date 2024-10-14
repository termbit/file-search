#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>
#include <ostream>
#include <sstream>
#include <string>
#include <fstream>

extern const char* user_filename;

void find_in_file(Fl_Widget* widget, void* data) {
	
    Fl_Input* text_input = static_cast<Fl_Input*>(data);
	const char* file_name = user_filename;
	
    const std::string orig_goal_text = text_input->value();
    std::string goal_text = orig_goal_text;
    

    std::fstream user_file(file_name);

    std::string curr_str_of_file = "";

    bool isFound = false;
    int str_num = 0;

    while (user_file) {
        std::getline(user_file, curr_str_of_file);

        for (int x = 0; x < curr_str_of_file.length(); ++x) {
            
            if (goal_text == "")
                break;

            if (curr_str_of_file[x] == goal_text[0])
            {
                isFound = true;
                goal_text.erase(goal_text.begin());
            }
            else {
                isFound = false;
                goal_text = orig_goal_text;
            }
        }

        ++str_num;

        if (goal_text == "")
        break;
    }

    std::ostringstream if_found;
    if_found << "Text found.\nLine: " << str_num;

    if (isFound) {
    	fl_message("%s", if_found.str().c_str());
    }
    else {
		fl_message("Text not found");
    }


};

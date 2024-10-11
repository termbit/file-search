#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_File_Chooser.H> 
#include <FL/fl_ask.H>
#include <string>
#include <fstream>

const char* user_filename;
const char* user_givven_text;

void file_chooser(Fl_Widget* widget, void* data) {
	user_filename = fl_file_chooser("", "", "");
}

void find_in_file(Fl_Widget* widget, void* data) {
	
    Fl_Input* text_input = static_cast<Fl_Input*>(data);
	const char* file_name = user_filename;
	
    const std::string orig_goal_text = text_input->value();
    std::string goal_text = orig_goal_text;
    

    std::fstream user_file(file_name);

    std::string curr_str_of_file = "";

    bool isFound = false;

    while (user_file) {
        std::getline(user_file, curr_str_of_file);

        for (int x = 0; x < curr_str_of_file.length(); ++x) {
            
            if (goal_text == "")
                break;

            if(curr_str_of_file[x] == goal_text[0])
            {
                isFound = true;
                goal_text.erase(goal_text.begin());
            }
            else {
                isFound = false;
                goal_text = orig_goal_text;
            }
        }

        if (goal_text == "")
        break;        
    }

    if (isFound) {
    	fl_message("Text found");
    }
    else {
		fl_message("Text not found");
    }

}

int main(int argc, char **argv) {

	Fl_Window *window = new Fl_Window(500,500, "Search in a file");
	Fl_Button *button = new Fl_Button(185, 90, 120, 30, "Choose a file");
	button->callback(file_chooser);
	
	Fl_Input *text_to_find = new Fl_Input(150, 140, 200, 30, "Text for find: ");

	Fl_Button *find_button = new Fl_Button(200, 250, 80, 30, "SEARCH");
	find_button->callback(find_in_file, text_to_find);



	window->end();
	window->show(argc, argv);
	return Fl::run();
}

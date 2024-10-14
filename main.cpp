#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_File_Chooser.H> 
#include <FL/fl_ask.H>
#include <FL/Fl_Output.H>
#include <cstring>

const char* user_filename;
// const char* user_givven_text;

void file_chooser(Fl_Widget* widget, void* data) {
	user_filename = fl_file_chooser("", "", "");
    
    Fl_Output* choosen_filename = static_cast<Fl_Output*>(data);
    const char* filename_for_output = strrchr(user_filename, '/');

    choosen_filename->value(filename_for_output + 1);
}

void find_in_file(Fl_Widget* widget, void* data);

int main(int argc, char **argv) {

	Fl_Window *window = new Fl_Window(500,300, "Search in a file");
	Fl_Button *file_choose_button = new Fl_Button(185, 90, 130, 30, "Choose a file");
	file_choose_button->labelsize(16);

    Fl_Output *choosen_filename = new Fl_Output(350, 90, 120, 30);
    Fl_Box *choosen_filename_label = new Fl_Box(350, 60, 100, 30, "Choosen file:");
    choosen_filename_label->labelsize(16);

	file_choose_button->callback(file_chooser, choosen_filename);

	Fl_Input *text_to_find = new Fl_Input(150, 140, 200, 30, "Text for find: ");
    text_to_find->labelsize(16);
    

	Fl_Button *find_button = new Fl_Button(205, 220, 90, 30, "SEARCH");
    find_button->labelsize(17);
	find_button->callback(find_in_file, text_to_find);
    find_button->shortcut(FL_Enter);

	window->end();
	window->show(argc, argv);
	return Fl::run();
}
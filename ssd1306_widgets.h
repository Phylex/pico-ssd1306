#include "ssd1306.h"
#include "text_buffer.h"
#include "font_struct.h"

#define CREATE_TEXT_BOX_WIDGET(width_, height_, pos_x_, pos_y_, font_struct_name_, text_box_name_) \
    text_buffer text_box_name_ ##_tbuffer;\
    ssd1306_textbox text_box_name_ = {\
	.pos_x = pos_x_,\
	.pos_y = pos_y_,\
	.width = width_,\
	.height = height_,\
	.fnt = &font_struct_name_,\
	.text_buffer = &text_box_name_ ## _tbuffer\
    }

typedef struct {
	uint16_t pos_x;
	uint16_t pos_y;
	uint16_t width;
	uint16_t height;
	const font *fnt;
	text_buffer *tb;
	bool updated;
} ssd1306_textbox;

void render_textbox(ssd1306_t *disp, ssd1306_textbox *text_widget);

void process_char(ssd1306_textbox *text_widget, char c);

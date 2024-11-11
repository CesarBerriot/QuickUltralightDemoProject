#include <quick_ultralight.h>
#include <stdlib.h>
#include <stdio.h>

static void document_object_model_ready_callback(void);
static JSValueRef counter_button_clicked_javascript_callback(JSContextRef, JSObjectRef function, JSObjectRef this_object, size_t argument_count, JSValueRef const arguments[], JSValueRef * exception);

int main(void)
{	qu_initialize("Cesar Berriot", "QuickUltralight Demo", "QuickUltralight Demo Window", 600, 400, true);
	qu_bind_callback(QU_CALLBACK_DOM_LOADED, document_object_model_ready_callback);
	qu_run();
	qu_cleanup();
	return 0;
}

static void document_object_model_ready_callback(void)
{	qu_register_javascript_function("counter_button_clicked_callback", counter_button_clicked_javascript_callback);
}

JSValueRef counter_button_clicked_javascript_callback(JSContextRef context, JSObjectRef function, JSObjectRef this_object, size_t argument_count, JSValueRef const * arguments, JSValueRef * exception)
{	char * current_value_string = qu_evaluate_script("document.getElementById('counter_button').innerText");
	int current_value = atoi(current_value_string);
	int new_value = current_value + 1;

	char format[] = "document.getElementById('counter_button').innerText = %i";
	int length = snprintf(NULL, 0, format, new_value);
	char buffer[length + 1];
	sprintf(buffer, format, new_value);
	qu_evaluate_script(buffer);

	return JSValueMakeNull(context);
}

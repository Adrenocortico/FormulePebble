#include "pebble.h"
#include "physics.h"
#include "electricity.h"
#include "ohms.h"
	
#define NUM_PHYSICS_MENU_ITEMS 10

static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections;

static SimpleMenuItem physics_menu_items[NUM_PHYSICS_MENU_ITEMS];

static void elec_select_callback(int index, void *ctx) {
  show_elec_menu();
}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
  window_destroy(window);
}

static void window_load(Window *window) {

  int num_a_items = 0;

  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Elettrostatica",
	.callback = elec_select_callback
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Kinematic Equation",
	.subtitle = "V1²=V0²+2a(∆x)"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Kinematic Equation",
	.subtitle = "d=Vi*t+½at²"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Kinematic Equation",
	.subtitle = "Vf=Vi+a*t"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Kinematic Equation",
	.subtitle = "d=(Vi+Vf/2)*t"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Kinetic Energy",
	.subtitle = "KE= 1/2mv²"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Work Formula",
	.subtitle = "W= F*d*cos(θ)"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Spring Potential E",
	.subtitle = "PE= 1/2*k*x²"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Potential Energy",
	.subtitle = "PE= m*g*h"
  };
  physics_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Kinetic Energy",
	.subtitle = "KE= 1/2m*v²"
  };
  menu_sections.num_items = NUM_PHYSICS_MENU_ITEMS;
  menu_sections.items = physics_menu_items;

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, &menu_sections, 1, NULL);
	
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void show_physics_menu(){
   window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
  
	
  window_stack_push(window, true /* Animated */);
}
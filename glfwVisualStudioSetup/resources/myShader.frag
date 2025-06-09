#version 330 core

layout(location = 0) out vec4 out_color;

in vec3 v_color;

void main() {
	vec4 red_color = vec4(1, 0, 0, 1);
	vec4 white_color = vec4(1, 1, 1, 1);
	float scaled_red_channel = floor(v_color.r * 10);
	float scaled_green_channel = floor(v_color.g * 10);
	float scaled_blue_channel = floor(v_color.b * 10);
	if (int(scaled_red_channel + scaled_blue_channel + scaled_green_channel) % 2 == 0) {
		out_color = red_color;
	} else {
		out_color = white_color;
	}
}

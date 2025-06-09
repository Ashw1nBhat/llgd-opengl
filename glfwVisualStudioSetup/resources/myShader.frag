#version 330 core

layout(location = 0) out vec4 out_color;

in vec3 v_color;

void main() {
	if (v_color.r > 0.5) {
		out_color = vec4(1, 0, 0, 1);
	} else if (v_color.g > 0.5) {
		out_color = vec4(0, 1, 0, 1);
	} else if (v_color.b > 0.5) {
		out_color = vec4(0, 0, 1, 1);
	} else {
		out_color = vec4(v_color, 1);
	}
}

#version 330 core

layout(location = 0) out vec4 out_color;

in vec3 v_color;

void main() {
	out_color = vec4(v_color.rgb * 10, 1);
	out_color = floor(out_color);
	if (int(out_color.r) % 2 == 0) {
		out_color = vec4(1, 0, 0, 1);
	} else {
		out_color = vec4(1, 1, 1, 1);
	}
}

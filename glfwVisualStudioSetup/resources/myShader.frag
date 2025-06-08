#version 330 core

layout(location = 0) out vec4 out_color;

in vec3 v_color;

void main() {
	out_color = vec4(1 - v_color.rgb, 1);
}

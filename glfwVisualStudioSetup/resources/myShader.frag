#version 330 core

layout(location = 0) out vec4 out_color;

in vec3 v_color;
in vec3 v_position;

void main() {
	vec3 position_to_color = (v_position + 1)/2;
	out_color = vec4(position_to_color.xy, 0.5, 1);	
}

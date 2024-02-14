
#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 resolution;
uniform vec2 mousedPosition;
uniform float time;

const int   complexity      = 50;
const float fluid_speed     = 22.0;
const float color_intensity = 1.0;
void main()
{
    vec2 p=(3.0*gl_FragCoord.xy-resolution)/max(resolution.x, resolution.y);

    for (int i=1;i<complexity;i++)
    {
        vec2 newp=p + time*0.00001;
        newp.x+=0.2/float(i)*sin(float(i)*p.y+time/fluid_speed+0.0*float(i+ 0)+ mousedPosition.x) + 0.6;
        newp.y+=0.8/float(i)*sin(float(i)*p.x+time/fluid_speed+0.0*float(i+ 0)+ mousedPosition.y) - 0.4;
        p=newp;
    }
    vec3 col=vec3(color_intensity*sin(4.0*p.x)+color_intensity, color_intensity*sin(2.0*p.y)+color_intensity, color_intensity*sin(p.x+p.y)+color_intensity);
    gl_FragColor=vec4(col, 0.7);
}
#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 resolution;
uniform float time;

void main() {
    vec2 uv = gl_FragCoord.xy / resolution.xy;
    float aspectRatio = resolution.x / resolution.y;

    // Базовая анимация, можно настраивать
    float smoke = sin(uv.x * 10.0 + time * 2.0) * 0.1;
    smoke += sin(uv.x * 5.0 + time * 3.0) * 0.05;

    // Добавим немного случайных волн для текстуры дыма
    vec2 distortion = vec2(
        sin(uv.y * 10.0 + time * 1.5),
        cos(uv.y * 15.0 + time * 2.0)
    ) * 0.005;

    uv += distortion;

    // Прозрачность зависит от координаты по y
    float transparency = 1.0 - uv.y * 0.5;

    // Цвет дыма
    vec3 color = vec3(0.7, 0.7, 0.7);

    // Смешиваем цвет с анимацией и прозрачностью
    color += smoke;
    color *= transparency;

    gl_FragColor = vec4(color, 1.0);
}

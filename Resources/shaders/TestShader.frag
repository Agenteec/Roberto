
/*uniform sampler2D texture;     // Текстура разрушаемого объекта
uniform float animationTime;   // Время анимации обломков
uniform vec2 resolution;      // Разрешение экрана
uniform vec2 debrisUV;        // Текстурные координаты для обломка

const int numFrames = 60;       // Количество кадров (подставьте свое значение)
const float frameDuration = 0.1; // Длительность одного кадра (подставьте свое значение)

void main() {
    vec2 uv = gl_FragCoord.xy / resolution;
    
    // Вычисляем текущий кадр анимации
    int currentFrame = int(mod(animationTime / frameDuration, float(numFrames)));

    // Вычисляем текстурные координаты для текущего кадра
    vec2 frameUV = debrisUV + vec2(float(currentFrame) / float(numFrames), 0.0);

    vec4 color = texture2D(texture, frameUV);

    // Рассчитываем анимацию движения и исчезновения
    float debrisAlpha = 1.0 - mod(animationTime, frameDuration) / frameDuration;
    
    // Умножаем цвет текстуры на альфа-канал обломков
    color.a *= debrisAlpha;

    gl_FragColor = color; // Результат фрагментного шейдера
}*/

uniform sampler2D texture; // Текстура разрушаемого объекта
uniform float animationTime; // Время анимации обломков
uniform vec2 resolution; // Разрешение экрана

void main() {
    vec2 uv = gl_FragCoord.xy / resolution;
    vec4 color = texture2D(texture, uv);

    // Пример анимации обломков: используйте модуль времени и координаты uv
    // для создания анимационного эффекта. В данном случае, мы просто будем
    // изменять альфа-канал (прозрачность) в зависимости от времени.
    float debrisAlpha = sin(animationTime) * 0.5 + 0.5; // Пример анимации

    // Умножаем цвет текстуры на альфа-канал обломков
    color.a *= debrisAlpha;

    gl_FragColor = color; // Результат фрагментного шейдера
}
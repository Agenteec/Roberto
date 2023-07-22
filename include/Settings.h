#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
using json = nlohmann::json;

std::string KeyToString(sf::Keyboard::Key key);
std::string ButtonToString(sf::Mouse::Button button);
std::string AxisToString(sf::Joystick::Axis axis);

class VideoSettings {
public:
    sf::VideoMode videoMode;
    sf::ContextSettings �ontext;
    bool fullscreen;
    bool verticalSyncEnabled;
    int framerateLimit;


    // ������ ��������� �����

    VideoSettings() :
        videoMode(800, 600),
        fullscreen(false),
        verticalSyncEnabled(false),
        framerateLimit(0)
    {}
    friend std::ostream& operator<<(std::ostream& os, const VideoSettings& settings) {
        os << "Video Settings:" << std::endl;
        os << "Resolution: " << settings.videoMode.width << "x" << settings.videoMode.height << std::endl;
        os << "Fullscreen: " << (settings.fullscreen ? "Enabled" : "Disabled") << std::endl;
        os << "Vertical Sync: " << (settings.verticalSyncEnabled ? "Enabled" : "Disabled") << std::endl;
        os << "Framerate Limit: " << settings.framerateLimit << std::endl;
        return os;
    }
};

class AudioSettings {
public:
    float volume;
    bool mute;
    // ������ ��������� �����

    AudioSettings() :
        volume(50.f),
        mute(false)
    {}
    friend std::ostream& operator<<(std::ostream& os, const AudioSettings& settings) {
        os << "Audio Settings:" << std::endl;
        os << "Volume: " << settings.volume << std::endl;
        os << "Mute: " << (settings.mute ? "Yes" : "No") << std::endl;
        // Add other audio settings if needed
        return os;
    }
};

class KeyboardSettings {
public:
    sf::Keyboard::Key moveUpKey;
    // ������ ��������� ����������

    KeyboardSettings() :
        moveUpKey(sf::Keyboard::W)
    {}
    friend std::ostream& operator<<(std::ostream& os, const KeyboardSettings& settings) {
        os << "Keyboard Settings:" << std::endl;
        os << "Move Up Key: " << KeyToString(settings.moveUpKey) << std::endl;
        // Add other keyboard settings if needed
        return os;
    }
};

class MouseSettings {
public:
    sf::Mouse::Button shootButton;

    MouseSettings() :
        shootButton(sf::Mouse::Left)
    {}
    friend std::ostream& operator<<(std::ostream& os, const MouseSettings& settings) {
        os << "Mouse Settings:" << std::endl;
        os << "Shoot Button: " << ButtonToString(settings.shootButton) << std::endl;
        return os;
    }
};





class Settings {
public:
    Settings();

    VideoSettings videoSettings;
    AudioSettings audioSettings;
    KeyboardSettings keyboardSettings;
    MouseSettings mouseSettings;

    /// <summary>
    /// �������� ���� �������� �� JSON �����
    /// </summary>
    /// <param name="file">��� �����</param>
    /// <returns></returns>
    bool LoadFromJson(std::string file = "settings.json");
    /// <summary>
    /// ���������� ���� �������� � JSON ����
    /// </summary>
    /// <param name="file">��� �����</param>
    /// <returns></returns>
    bool SaveFromJson(std::string file = "settings.json");
    friend std::ostream& operator<<(std::ostream& os, const Settings& settings) {
        os << "All Settings:" << std::endl;
        os << settings.videoSettings << settings.audioSettings << settings.keyboardSettings << settings.mouseSettings << std::endl;
        return os;
    }

};





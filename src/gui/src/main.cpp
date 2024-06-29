#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("hello_ros2_node");

    auto publisher = node->create_publisher<std_msgs::msg::String>("chatter", 10);

    std::string hello_msg = "Hello, ROS2 from Qt!";
    auto msg = std::make_shared<std_msgs::msg::String>();
    msg->data = hello_msg;

    publisher->publish(*msg);

    // Qt application setup
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    int ret = app.exec();

    rclcpp::shutdown();
    return ret;
}

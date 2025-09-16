#include <qrhi.h>
#include <QDebug>

class MyGpuResource {
public:
    MyGpuResource(const QString &name) : m_name(name) {
        qDebug() << "Created resource:" << m_name;
    }

    ~MyGpuResource() {
        qDebug() << "Destroyed resource:" << m_name;
    }

private:
    QString m_name;
};

// Define the cleanup function
void myCleanupCallback(void *param) {
    MyGpuResource *res = static_cast<MyGpuResource *>(param);
    delete res;
    qDebug() << "Custom cleanup callback executed.";
}

int main(int argc, char **argv)
{
    // Normally you would create a QRhi instance using a backend, e.g., Vulkan, D3D, Metal.
    // But here, we assume you already have a QRhi* (called `rhi`), like from QRhi::create()

    QRhi *rhi = /* QRhi::create(...) or provided by your app */ nullptr;

    // Example only works if you have a valid rhi instance
    if (!rhi) {
        qWarning() << "QRhi instance not available. Cannot proceed.";
        return -1;
    }

    // Create a custom GPU resource (simulate one)
    MyGpuResource *resource = new MyGpuResource("TestResource");

    // Register cleanup callback
    rhi->addCleanupCallback(myCleanupCallback, resource);

    // At this point, when rhi is released/destroyed, `myCleanupCallback` will be called
    // and delete your `MyGpuResource` object.

    // Destroy rhi (usually at app shutdown)
    delete rhi;

    return 0;
}

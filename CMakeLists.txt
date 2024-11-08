cmake_minimum_required(VERSION 3.24)

project(TestCryptoWallet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.2 COMPONENTS Quick QuickControls2 REQUIRED)

qt_add_executable(appTestCryptoWallet
    images.qrc
    main.cpp
    version.h
    qmlcontext.h
    qmlcontext.cpp
    address.h
    address.cpp
    tx.h
    tx.cpp
    addresslistmodel.h
    addresslistmodel.cpp
    txlistmodel.h
    txlistmodel.cpp
    clipboardmodel.h
    clipboardmodel.cpp



)

qt_add_qml_module(appTestCryptoWallet
    URI TestCryptoWallet
    VERSION 1.0
    QML_FILES ui/main.qml
    QML_FILES ui/WApplicationWindow.qml
    QML_FILES ui/AddressListPane.qml
    QML_FILES ui/dialogs/WDialog.qml
    QML_FILES ui/dialogs/AddressTxDialog.qml
    QML_FILES ui/dialogs/SettingsDialog.qml
    QML_FILES ui/ApplicationManager.qml
    QML_FILES ui/AddressTxListView.qml
    QML_FILES ui/AddressItem.qml
    QML_FILES ui/TxListPane.qml
    QML_FILES ui/TxItem.qml
    QML_FILES
)

set_target_properties(appTestCryptoWallet PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTestCryptoWallet
    PRIVATE Qt6::Quick Qt6::QuickControls2)

install(TARGETS appTestCryptoWallet
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

#include "AppDelegate.h"
#include "PlayLayer.h"

USING_NS_CC;

AppDelegate::AppDelegate(){}
AppDelegate::~AppDelegate() {}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("Sushi crush");
        director->setOpenGLView(glview);
    }
    
    glview->setDesignResolutionSize(320.0f, 480.0f, ResolutionPolicy::FIXED_WIDTH);
    std::vector<std::string> searchPath;
    searchPath.push_back("w640");
    CCFileUtils::getInstance()->setSearchPaths(searchPath);
    director->setContentScaleFactor(640.0f / 320.0f);

    // turn on display FPS
    director->setDisplayStats(true);

    // フレームレート設定
    director->setAnimationInterval(1.0 / 60);

    // シーン作成
    auto scene = PlayLayer::createScene();
    

    // 実行
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

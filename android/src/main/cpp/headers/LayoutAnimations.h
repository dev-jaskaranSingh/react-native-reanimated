//
// Created by Szymon Kapala on 4/15/21.
//

#ifndef REANIMATEDEXAMPLE_LayoutAnimations_H
#define REANIMATEDEXAMPLE_LayoutAnimations_H
#include <fbjni/fbjni.h>
#include <jsi/jsi.h>
#include "JNIHelper.h"

namespace reanimated
{

using namespace facebook::jni;
using namespace facebook;

class LayoutAnimations : public jni::HybridClass<LayoutAnimations> {
 public:
  static auto constexpr kJavaDescriptor =
      "Lcom/swmansion/reanimated/layoutReanimation/LayoutAnimations;";
  static jni::local_ref<jhybriddata> initHybrid(
        jni::alias_ref<jhybridobject> jThis);
  static void registerNatives();

  void LayoutAnimations::startAnimationForTag(int tag, Jstring type, alias_ref<JMap<jstring, jstring>> values);
  void removeConfigForTag(int tag);

  void setWeakUIRuntime(std::weak_ptr<jsi::Runtime> wrt);

  void notifyAboutProgress(jsi::Value progress, int tag);
  void notifyAboutEnd(int tag, int cancelled);

 private:
  friend HybridBase;
  jni::global_ref<LayoutAnimations::javaobject> javaPart_;
  std::weak_ptr<jsi::Runtime> weakUIRuntime;

  explicit LayoutAnimations(jni::alias_ref<LayoutAnimations::jhybridobject> jThis);
};

};
#endif //REANIMATEDEXAMPLE_LayoutAnimations_H
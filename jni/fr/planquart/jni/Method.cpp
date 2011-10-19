#include "Method.hpp"
#include "Class.hpp"

using namespace fr::Planquart::JNI;

Method::Method(JNIEnv* env, Class* classObject, Signature* signature, bool isStatic)
	:classObject{classObject}, signature{signature}, _static{isStatic}
{
	if (_static)
	{
		this->methodID = env->GetStaticMethodID(
				this->classObject->getClassObject(env),
				this->signature->getName(),
				this->signature->getType());
	}
	else
	{
		this->methodID = env->GetMethodID(
				this->classObject->getClassObject(env),
				this->signature->getName(),
				this->signature->getType());
	}
}


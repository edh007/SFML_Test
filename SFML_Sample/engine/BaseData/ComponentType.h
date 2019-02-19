#pragma once

#include <string>

enum ComponentType {

    CT_NONE,

    CT_TRANSFORM,

    CT_END
};

inline ComponentType ComponentTypeConverter(const std::string& key)
{
    // Define components

    if (key == "TRANSFORM")
        return CT_TRANSFORM;
    else
        return CT_NONE;
}

inline void RegisterComponents(void)
{
    //std::thread ct_thread[CT_END];
    //ct_thread[CT_TRANSFORM] = std::thread(ComponentFactory::AddBuilder, CT_TRANSFORM, new TransformBuilder);
    //ct_thread[CT_RIGIDBODY] = std::thread(ComponentFactory::AddBuilder, CT_RIGIDBODY, new RigidBodyBuilder);

    //ct_thread[CT_TEXT] = std::thread(ComponentFactory::AddBuilder, CT_TEXT, new TextBuilder);
    //ct_thread[CT_SPRITE] = std::thread(ComponentFactory::AddBuilder, CT_SPRITE, new SpriteBuilder);
    //ct_thread[CT_PARTICLE] = std::thread(ComponentFactory::AddBuilder, CT_PARTICLE, new ParticleBuilder);

    //for (int ct_num = 0; ct_num < CT_END; ++ct_num)
    //	if (ct_thread[ct_num].joinable())
    //		ct_thread[ct_num].join();

    // Basic Component
    //ComponentFactory::AddBuilder(CT_TRANSFORM, new TransformBuilder);
}
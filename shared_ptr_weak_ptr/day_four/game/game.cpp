#include<iostream>
#include<memory>
#include<vector>

struct Component{
    virtual ~Component(){
        std::cout << "Component has been destroyed" << '\n';
    }
};

struct PhysicsComponent : Component{
    ~PhysicsComponent(){
        std::cout << "Physics component has been destroyed" << '\n';
    }
};

struct RenderComponent : Component{
    ~RenderComponent(){
        std::cout << "Render component has been destroyed" << '\n';
    }
};

struct GameObject{

    std::vector<std::unique_ptr<Component>> components;
    
    ~GameObject(){
        std::cout << "Object has been destroyed" << '\n';
    }

};

int main(){
    auto phcomponent = std::make_unique<PhysicsComponent>();
    auto rncomponent = std::make_unique<RenderComponent>();
    auto object = std::make_unique<GameObject>(); 
    
    object -> components.push_back(std::move(phcomponent));
    object -> components.push_back(std::move(rncomponent));
}

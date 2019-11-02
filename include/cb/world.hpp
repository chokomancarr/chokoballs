#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* A world instance
 * 
 */
class World {
public:
	World();

	/* -- parameters --
	 * these must be set for the
	 * updates to work properly
	 */

	/*
	 */
	float deltaTime;

	float timeScale;

    std::vector<pObject> objects;

	/* Creates a new world
     */
    static pWorld Create();
    
    /* Removes all contents in this world
     */
    void Clear();
    
    /* Attaches an object reference to this world
     */
    void AddObject(const pObject&);
    
    /* Removes an object reference to this world
     */
    void RemoveObject(const pObject&);

	/* Starts a physics update
	 * The actual update is performed in a different thread
	 * This function returns after sending data to the compute backend
	 */
	CB_STATUS BeginUpdate();

	/* Finishes the physics update
	 * This function blocks until the update is finished
	 */
	CB_STATUS FinishUpdate();
};

CB_END_NAMESPACE
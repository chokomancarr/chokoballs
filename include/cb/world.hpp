#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* A world instance
 * 
 */
class _World {
public:
	_World();

	/* -- parameters --
	 * these must be set for the
	 * updates to work properly
	 */

	/*
	 */
	float deltaTime;

	float timeScale;

	float gravity;

    std::vector<Object> objects;
    
    /* Removes all contents in this world
     */
    void Clear();
    
    /* Attaches an object reference to this world
     */
    void AddObject(const Object&);
    
    /* Removes an object reference to this world
     */
    void RemoveObject(const Object&);

	/* Starts a physics update
	 * The actual update is performed in a different thread
	 * This function returns after sending data to the compute backend
	 * Reading / writing values between BeginUpdate and FinishUpdate
	 * calls are undefined behaviour
	 */
	CB_STATUS BeginUpdate();

	/* Finishes the physics update
	 * This function blocks until the update is finished
	 * This function does nothing if there are no active threads
	 */
	CB_STATUS FinishUpdate();

	CB_STATUS Raycast(const Ray& ray, const uint64_t mask, RayHit& result);
};

CB_END_NAMESPACE
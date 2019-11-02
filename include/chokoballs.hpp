#pragma once
#include "cb/chokoballs_includes.hpp"
#include "cb/enums/backend_type.hpp"

CB_BEGIN_NAMESPACE

class ChokoBalls {
	static BACKEND_TYPE backendType;

	static pBackend_Base backend;

public:
	/* Selects the compute backend.
	 * If not specified, the first supported backend is used.
	 * This call has no effect after Init.
	 */
	static void SetBackend(BACKEND_TYPE);

    /* Initializes the API.
     * This should be called before everything else,
     * except optionally after SetBackend.
     */
    static CB_STATUS Init();

    /* Finalizes the API.
     * This should be the very last call.
     */
    static void Finalize();

	friend class World;
};

CB_END_NAMESPACE
// E-BOT API
// most of natives returns true after execution, otherwise false
#define EBOT_API

enum Process
{
    Default = 0,
	Pause,
	DestroyBreakable,
	ThrowHE,
	ThrowFB,
	ThrowSM,
	Blind,
	UseButton,
	Override
};

// defines for waypoint flags field
enum _:WaypointFlag
{
	WAYPOINT_LIFT = (1 << 1), // wait for lift to be down before approaching this waypoint
	WAYPOINT_CROUCH = (1 << 2), // must crouch to reach this waypoint
	WAYPOINT_CROSSING = (1 << 3), // a target waypoint
	WAYPOINT_GOAL = (1 << 4), // mission goal point (bomb, hostage etc.)
	WAYPOINT_LADDER = (1 << 5), // waypoint is on ladder
	WAYPOINT_RESCUE = (1 << 6), // waypoint is a hostage rescue point
	WAYPOINT_CAMP = (1 << 7), // waypoint is a camping point
	WAYPOINT_DJUMP = (1 << 9), // bot help's another bot (requster) to get somewhere (using djump)
	WAYPOINT_ZMHMCAMP = (1 << 10), // bots will camp at this waypoint
	WAYPOINT_AVOID = (1 << 11), // bots will avoid these waypoints mostly
	WAYPOINT_USEBUTTON = (1 << 12), // bots will use button
	WAYPOINT_HMCAMPMESH = (1 << 13), // human camp mesh
	WAYPOINT_ZOMBIEONLY = (1 << 14), // only zombie bots can use this waypoint
	WAYPOINT_HUMANONLY = (1 << 15), // only humans bots can use this waypoint
	WAYPOINT_ZOMBIEPUSH = (1 << 16), // zombies never return back on this waypoint
	WAYPOINT_FALLRISK = (1 << 17), // bots never do strafing while on this waypoint
	WAYPOINT_SPECIFICGRAVITY = (1 << 18), // specific jump gravity check for bot
	WAYPOINT_ONLYONE = (1 << 19), // to avoid multiple bots stuck on same waypoint
	WAYPOINT_WAITUNTIL = (1 << 20), // inverse fall check
	WAYPOINT_HELICOPTER = (1 << 21), // helicopter for zombie escape maps
	WAYPOINT_FALLCHECK = (1 << 26), // bots will check ground
	WAYPOINT_JUMP = (1 << 27), // for jump points
	WAYPOINT_SNIPER = (1 << 28), // it's a specific sniper point
	WAYPOINT_TERRORIST = (1 << 29), // it's a specific terrorist point
	WAYPOINT_COUNTER = (1 << 30)  // it's a specific ct point
};

// checks if ebot is running
native bool:is_ebot_running();

// returns ebot version
native Float:get_ebot_version();

// checks if user is ebot
native is_user_ebot(index);

// checks if ebot sees enemy
native ebot_sees_enemy(index);

// checks if ebot sees entity
native ebot_sees_entity(index);

// checks if ebot sees frient
native ebot_sees_friend(index);

// return ebot's current enemy, also returns last enemy
native ebot_get_enemy(index);

// return ebot's current entity, also returns last entity
native ebot_get_entity(index);

// return ebot's current friend, also returns last friend
native ebot_get_friend(index);

// return ebot's current friend, also returns last friend
native ebot_get_friend(index);

// sets the ebot's current/last enemy
native ebot_set_enemy(index, index2);

// sets the ebot's current/last entity
native ebot_set_entity(index, index2);

// sets the ebot's current/last friend
native ebot_set_friend(index, index2);

// returns distance of the current enemy
native Float:ebot_get_enemy_distance(index);

// returns distance of the current entity
native Float:ebot_get_entity_distance(index);

// returns distance of the current friend
native Float:ebot_get_friend_distance(index);

// overrides ebot to look at given vector
native ebot_set_look_at(index, Float:lookAt[3]);

// return's ebot's current process
native ebot_get_current_process(index);

// returns ebot's remembered process
native ebot_get_remembered_process(index);

// returns remaining time to exit from current process
native Float:ebot_get_current_process_time(index);

// returns remaining time to forget remembered process
native Float:ebot_get_remembered_process_time(index);

// sets the current process if requirements are satisfied
native ebot_set_current_process(index, process, remember, Float:time);

// forces the current process even if requirements are not satisfied
native ebot_force_current_process(index, process);

// finishes current process no matter what
native amxx_ebot_finish_current_process(index);

// overrides current process, useful for custom scenario and bot tasks
// custom id is for check if bot is already overriden by another plugin or not
// by default bot can look at around and shoot enemies
// default checks are enemy, friend and reachability checks
// bot doesn't find path by default but if already has path it can follow it
native ebot_override_current_process(index, remember, Float:time, customID, defaultLookAI = true, defaultChecks = true);

// returns the custom id of override process, returns 0 if its not overrided
native ebot_get_override_process_id(index);

// returns true if bot has default override checks, such as finding visible enemies/friends and reachability check
native ebot_has_override_checks(index);

// return true if bot can look at around and shoot enemies by default while overriding existing process
native ebot_has_override_look_ai(index);

// calls ebot's FireWeapon function, returns true it ebot is found
native ebot_force_fire_weapon(index, Float:targetDistance);

// calls ebot's look at around ai but just looks at around, useful when default look ai is disabled
native ebot_look_at_around(index);

// calls ebot's NewRound function (also called when ebot spawns), useful if bot cannot detect respawn by default
native ebot_call_new_round(index);

// should ebot ignore this user? useful in custom mods
native ebot_set_ignore_user(index, ignore = false);

// returns true if user is ignored
native ebot_is_user_ignored(index);

// returns the waypoint which close and reachable to user
native ebot_get_user_waypoint(index);

// returns true if user logined via ebot_pass
native ebot_is_user_owner(index);

// ebot's way of is_user_connected
native ebot_is_user_in_game(index);

// ebot's way of is_user_alive
native ebot_is_user_alive(index);

// returns true if current enemy can reach by just walking
native ebot_is_enemy_reachable(index);

// sets current enemy's reachability
native ebot_set_enemy_reachable(index);

// returns true if ebot is stuck
native ebot_is_stuck(index);

// returns the time how long ebot is stuck
native Float:ebot_get_stuck_time(index);

// returns the ammo of given weapon id
native ebot_get_ammo(index, weaponID);

// returns the ammo in current weapon's clip
native ebot_get_ammo_in_clip(index);

// returns the current weapon of ebot
native ebot_get_current_weapon(index);

// forces ebot to select knife
native ebot_select_knife(index);

// forces ebot to select best weapon
native ebot_select_best_weapon(index);

// retuns true if slowThink is active, every one second
native ebot_is_slow_think(index);

// sets the current slowThink state
native ebot_set_slow_think(index, slowThink = true);

// returns true if ebot is zombie
native ebot_is_zombie(index);

// sets ebot as zombie
native ebot_set_zombie(index, isZombie = false);

// returns true if ebot is alive
native ebot_is_alive(index);

// sets ebot as alive
native ebot_set_alive(index, isAlive = true);

// returns number of waypoints loaded
native ebot_get_waypoint_number();

// returns origin of given waypoint index
native ebot_get_waypoint_origin(waypointIndex, Float:origin[3]);

// returns flags of given waypoint index
native ebot_get_waypoint_flags(waypointIndex, flags);

// returns radius of given waypoint index
native ebot_get_waypoint_radius(waypointIndex, radius);

// returns mesh id of given waypoint index
native ebot_get_waypoint_mesh(waypointIndex, meshID);

// returns connection index of given waypoint index
native ebot_get_waypoint_connections(waypointIndex, connectionIndex, connectionNumber);

// returns connection flags of given waypoint index
native ebot_get_waypoint_connections(waypointIndex, connectionFlags, connectionNumber);

// returns gravity of given waypoint index
native ebot_get_waypoint_gravity(waypointIndex, gravity);

// forces ebot to move towards given vector
native ebot_move_to(index, Float:origin[3]);

// forces ebot to move in the opposite direction of the given vector
native ebot_move_out(index, Float:origin[3]);

// finds path to given waypoint index, deletes current path when new path is found
native ebot_find_path_to(index, goalWaypointIndex);

// faster version of find_path, it doesn't check for zombies, etc.
native ebot_find_shortest_path_to(index, goalWaypointIndex);

// returns the current waypoint of ebot
native ebot_get_current_waypoint(index);

// returns the goal waypoint of ebot
native ebot_get_goal_waypoint(index);

// sets the current waypoint of ebot
native ebot_set_current_waypoint(index, waypointIndex);

// sets the goal waypoint of ebot
native ebot_set_goal_waypoint(index, waypointIndex);

// returns index of current human camp waypoint
native ebot_get_camp_waypoint(index);

// returns index of current mesh camp waypoint
native amxx_ebot_get_mesh_waypoint(index);

// returns true if ebot can follow path, path is valid, ebot_follow_path is used and etc.
native ebot_can_follow_path(index);

// starts pathing, use if ebot has valid path without using this ebot_can_follow_path is useless
native ebot_follow_path(index);

// forces ebot to stop following path
native ebot_stop_following_path(index);

// forces ebot to go next path, skips current one
native ebot_shift_path(index);

// deletes current path of ebot
native ebot_clear_path(index);

// returns waypoint index of path
native ebot_get_path(index, pathNumber = 0);

// returns length of current path
native ebot_get_path_length(index);

// returns true if both vectors are reachable
native ebot_is_node_reachable(Float:vec1[3], Float:vec2[3]);

// returns nearest waypoint index to given vector
native ebot_find_nearest_waypoint(Float:origin[3], Float:maxDistance);

// returns farest waypoint index to given vector
native ebot_find_farest_waypoint(Float:origin[3], Float:maxDistance);

// returns nearest reachable waypoint index to given entity index and given vector, origin also can be entity origin
native ebot_find_nearest_waypoint(Float:origin[3], Float:maxDistance, entityIndex);

// returns path distance between two waypoints
native ebot_get_waypoint_distance(srcIndex, destIndex);

// returns true if given waypoint index is valid
native ebot_is_valid_waypoint(waypointIndex);

// return true if path matrix is ready
native ebot_is_matrix_ready();

// returns true if ebot is camping
native ebot_is_camping(index);

// returns true if successful, bots will look and attack enemy entities
native ebot_register_enemy_entity(entityIndex);

// returns true if unregister is successful
native ebot_unregister_enemy_entity(entityIndex);

// unregisters every entity
native ebot_clear_all_registered_enemy_entities();

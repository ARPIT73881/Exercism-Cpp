namespace hellmath
{

    // Task 1: Define an `AccountStatus` enumeration to represent the four account types
    enum class AccountStatus
    {
        troll,
        guest,
        user,
        mod
    };

    // Task 1: Define an `Action` enumeration to represent the three permission types
    enum class Action
    {
        read,
        write,
        remove
    };

    // Task 2: Implement the `display_post` function
    bool display_post(AccountStatus poster, AccountStatus viewer)
    {
        if (poster == AccountStatus::troll)
        {
            // Troll posts are visible only to trolls
            return viewer == AccountStatus::troll;
        }
        // Non-troll posts are visible to everyone
        return true;
    }

    // Task 3: Implement the `permission_check` function
    bool permission_check(Action action, AccountStatus status)
    {
        switch (status)
        {
        case AccountStatus::guest:
            return action == Action::read;
        case AccountStatus::troll:
            return action == Action::read || action == Action::write;
        case AccountStatus::user:
            return action == Action::read || action == Action::write;
        case AccountStatus::mod:
            return true; // Mods can perform all actions
        default:
            return false;
        }
    }

    // Task 4: Implement the `valid_player_combination` function
    bool valid_player_combination(AccountStatus player1, AccountStatus player2)
    {
        // Guests cannot play with anyone
        if (player1 == AccountStatus::guest || player2 == AccountStatus::guest)
        {
            return false;
        }

        // Trolls can only play with other trolls
        if (player1 == AccountStatus::troll || player2 == AccountStatus::troll)
        {
            return player1 == AccountStatus::troll && player2 == AccountStatus::troll;
        }

        // Users can play with users or mods
        if (player1 == AccountStatus::user || player2 == AccountStatus::user)
        {
            return player1 == AccountStatus::user || player2 == AccountStatus::user || player1 == AccountStatus::mod || player2 == AccountStatus::mod;
        }

        // Mods can play with users or other mods
        return true;
    }

    // Task 5: Implement the `has_priority` function
    bool has_priority(AccountStatus player1, AccountStatus player2)
    {
        // Define priority levels: mod > user > guest > troll
        int priority1 = 0, priority2 = 0;

        switch (player1)
        {
        case AccountStatus::mod:
            priority1 = 4;
            break;
        case AccountStatus::user:
            priority1 = 3;
            break;
        case AccountStatus::guest:
            priority1 = 2;
            break;
        case AccountStatus::troll:
            priority1 = 1;
            break;
        }

        switch (player2)
        {
        case AccountStatus::mod:
            priority2 = 4;
            break;
        case AccountStatus::user:
            priority2 = 3;
            break;
        case AccountStatus::guest:
            priority2 = 2;
            break;
        case AccountStatus::troll:
            priority2 = 1;
            break;
        }

        // Return true if player1 has strictly higher priority than player2
        return priority1 > priority2;
    }

} // namespace hellmath

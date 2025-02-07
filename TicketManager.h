#ifndef TICKET_MANAGER_H
#define TICKET_MANAGER_H
#include <string>

class TicketManager {
public:
    static void bookTicket(const std::string& username);
    static void viewBookings(const std::string& username);
};

#endif // TICKET_MANAGER_H

#include "Item.h"

Deleted_Item *Deleted_Item::entry = nullptr;


Deleted_Item* Deleted_Item::get_Item()
{
    if (entry == nullptr)
    {
        entry = new Deleted_Item();
    }

    return entry;
}

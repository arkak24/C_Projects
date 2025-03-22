#pragma once

#include "std_db.h"     // file_handler.c -> needs struct student -> comes from std_db.h

void load_database_from_file(void);
void save_database_to_file(void);
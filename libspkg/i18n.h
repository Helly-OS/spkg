#include <libintl.h>
#include <locale.h>

#ifndef I18N_INCLUDED_H
#define I18N_INCLUDED_H

#define t_(STRING) gettext(STRING)
#define l_(STRING) dgettext("libspkg-1.0",STRING)

#endif

/*
    This file is part of darktable,
    copyright (c) 2014 Henrik Andersson.

    darktable is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    darktable is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with darktable.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _IMPORT_SESSION_H
#define _IMPORT_SESSION_H

struct dt_import_session_t;

struct dt_import_session_t *dt_import_session_new();
void dt_import_session_destroy(struct dt_import_session_t *self);

/** \brief Verify that we use current film and import images into it */
gboolean dt_import_session_ready(struct dt_import_session_t *self);

/** \brief add reference to specified import session */
void dt_import_session_ref(struct dt_import_session_t *self);
/** \brief remove reference to specified import session */
void dt_import_session_unref(struct dt_import_session_t *self);

/** \brief import of current filename to session film roll */
void dt_import_session_import(struct dt_import_session_t *self);

/** \brief set the job code of the specific import session */
void dt_import_session_set_name(struct dt_import_session_t *self, const char *name);

/** \brief override the time for specific import session
    \remark This will override NOW timestamp with specified one used when expanding ${YEAR} and alike.
*/
void dt_import_session_set_time(struct dt_import_session_t *self, time_t time);

/** \brief set the orginal filename
    \remark This is used to expand $(FILE_X) variables. */
void dt_import_session_set_filename(struct dt_import_session_t *self, const char *filename);

/** \brief current film id for the import session */
int32_t dt_import_session_film_id(struct dt_import_session_t *self);

/** \brief get import session name */
const char *dt_import_session_name(struct dt_import_session_t *self);
/** \brief get import session filename.
    \param[in] current If TRUE the current filename will be return without evaluting a new filename.
 */
const char *dt_import_session_filename(struct dt_import_session_t *self, gboolean current);
/** \brief get import session path
    \param[in] current If TRUE the current filename will be return without evaluting a new filename.
*/
const char *dt_import_session_path(struct dt_import_session_t *self, gboolean current);

#endif
// modelines: These editor modelines have been set for all relevant files by tools/update_modelines.sh
// vim: shiftwidth=2 expandtab tabstop=2 cindent
// kate: tab-indents: off; indent-width 2; replace-tabs on; indent-mode cstyle; remove-trailing-spaces modified;

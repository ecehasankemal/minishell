#include "lexer.h"
#include "env.h"
#include "exec.h"
#include "printer.h"

static inline t_list	*token_list_get(char *input);
static inline int		redir_mark_files(t_list	*l_token);

t_list	*lexer(char *input)


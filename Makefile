# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 19:16:51 by abarnett          #+#    #+#              #
#    Updated: 2020/01/25 07:46:52 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			stats
SRCS_DIR :=		srcs
INCLUDES_DIR :=	includes

CXX :=			clang++
CXXFLAGS :=		-Wall -Wextra -Werror -I$(INCLUDES_DIR)
LDFLAGS :=		-lncurses
RM :=			/bin/rm -f

# Don't modify below here
# **************************************************************************** #

SRCS :=			$(wildcard $(SRCS_DIR)/*.cc)
DEPS :=			$(patsubst %.cc,%.d,$(SRCS))
OBJS :=			$(patsubst %.cc,%.o,$(SRCS))

.PHONY:		all clean fclean re

all:		tags $(NAME)

tags:		$(SRCS)
	@ ctags -R

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o:		%.cc Makefile
	$(CXX) $(CXXFLAGS) -MMD -MT $@ -o $@ -c $<

-include $(DEPS)

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

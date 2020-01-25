# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 19:16:51 by abarnett          #+#    #+#              #
#    Updated: 2020/01/25 04:11:53 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		stats
SRCS :=		main.cc IMonitorModule.cc IMonitorDisplay.cc
OBJS :=		$(patsubst %.cc,%.o,$(SRCS))

CXX :=		clang++
CXXFLAGS :=	-Wall -Wextra -Werror
LDFLAGS :=
RM :=		/bin/rm -f

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

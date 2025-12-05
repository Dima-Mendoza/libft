cmake_minimum_required(VERSION 3.15)
project(Libft C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_fLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

# сама библиотека libft
add_library(ft
        ft_memset.c
        ft_bzero.c
        ft_memcmp.c
        ft_memmove.c
        # другие файлы libft
)

# исполняемый файл с main
add_executable(Libft
        main.c
        ft_bzero.c
        ft_memcmp.c
        ft_memmove.c
)

target_link_libraries(Libft PRIVATE ft)

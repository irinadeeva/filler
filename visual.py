# Pygame шаблон - скелет для нового проекта Pygame
import pygame
import random

WIDTH = 1500  # ширина игрового окна
HEIGHT = 1700 # высота игрового окна
FPS = 30 # частота кадров в секунду

# Задаем цвета
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)


class Player(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((50, 50))
        self.image.fill(GREEN)
        self.rect = self.image.get_rect()
        self.rect.center = (WIDTH / 17 * 3 , HEIGHT / 15 * 9 )


    def update(self):
        self.rect.x += 5
        if self.rect.left > WIDTH:
            self.rect.right = 0



# Создаем игру и окно
pygame.init()  #  это команда, которая запускает pygame
pygame.mixer.init() # для звука
screen = pygame.display.set_mode((WIDTH, HEIGHT)) #  окно программы, которое создается, когда мы задаем его размер в настройках
pygame.display.set_caption("My Game")
clock = pygame.time.Clock() # необходимо создать clock, чтобы убедиться, что игра работает с заданной частотой кадров.
all_sprites = pygame.sprite.Group()
player = Player()
all_sprites.add(player)


# Цикл игры
running = True
while running:
    # Держим цикл на правильной скорости
    clock.tick(FPS)
    # Ввод процесса (события)
    for event in pygame.event.get():
        # check for closing window
        if event.type == pygame.QUIT:
            running = False

    # Обновление
   # all_sprites.update()

    # Рендеринг
    screen.fill(BLACK)
    all_sprites.draw(screen)
    # После отрисовки всего, переворачиваем экран
    pygame.display.flip()

pygame.quit()
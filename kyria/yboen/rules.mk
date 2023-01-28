OLED_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
MOUSEKEY_ENABLE = yes
COMBO_ENABLE = yes
MUSIC_ENABLE = no
MAGIC_ENABLE = no

ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += my_encoder.c
endif

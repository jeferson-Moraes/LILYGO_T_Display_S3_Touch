#include "pin_config.h"


#define color1 0x33AE  //body
#define color2 0x22CE //number region
#define color3 0x2C8E  //buttons region


#define latin Latin_Hiragana_24
#define small NotoSansBold15
#define sans20 NotoSansMonoSCB20 
#define star Final_Frontier_28

lv_obj_t *circle_obj;  // Objeto do círculo
lv_obj_t *button;      // Objeto do botão

// Função que será chamada quando o botão for clicado
static void change_color_event_cb(lv_event_t *e)
{
    // Verificar se o círculo existe
    if(circle_obj == NULL) return;  // Proteção para evitar acessar um objeto nulo

    // Obtém a cor atual do círculo
    lv_color_t current_color = lv_obj_get_style_bg_color(circle_obj, LV_PART_MAIN);

    // Comparar a cor atual diretamente pelos componentes RGB
    if (current_color.full == lv_color_hex(0x00FF00).full) {  // Verde
        lv_obj_set_style_bg_color(circle_obj, lv_color_hex(0xFF0000), LV_PART_MAIN);  // Mudar para vermelho
    } else {
        lv_obj_set_style_bg_color(circle_obj, lv_color_hex(0x00FF00), LV_PART_MAIN);  // Mudar para verde
    }

    // Atualizar a tela para refletir a mudança de cor
    lv_obj_invalidate(circle_obj);  // Forçar o LVGL a redesenhar o círculo
}

// Função que cria o círculo verde e o botão na tela preta
void create_circle_and_button()
{
    // Configura a tela com o fundo preto
    lv_obj_t *screen = lv_scr_act();
    lv_obj_set_style_bg_color(screen, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, LV_PART_MAIN);

    // Criando o círculo verde
    circle_obj = lv_obj_create(screen);
    lv_obj_set_size(circle_obj, 100, 100);  // Definir tamanho do círculo
    lv_obj_set_style_radius(circle_obj, LV_RADIUS_CIRCLE, LV_PART_MAIN);  // Tornar o objeto circular
    lv_obj_set_style_bg_color(circle_obj, lv_color_hex(0x00FF00), LV_PART_MAIN);  // Verde
    lv_obj_align(circle_obj, LV_ALIGN_CENTER, 0, -50);  // Alinhar o círculo no centro, mas um pouco para cima

    // Criando o botão abaixo do círculo
    button = lv_btn_create(screen);  // Cria o botão
    lv_obj_set_size(button, 80, 40);  // Define o tamanho do botão
    lv_obj_align(button, LV_ALIGN_CENTER, 0, 80);  // Alinha o botão abaixo do círculo

    // Adicionando texto ao botão
    lv_obj_t *label = lv_label_create(button);  // Cria um rótulo no botão
    lv_label_set_text(label, "Cor");  // Define o texto como "Cor"
    lv_obj_center(label);  // Centraliza o texto no botão

    // Configurando o callback do evento de clique no botão
    lv_obj_add_event_cb(button, change_color_event_cb, LV_EVENT_CLICKED, NULL);
}











LV_IMG_DECLARE(app_settings_img);
LV_IMG_DECLARE(app_wifi_img);
LV_IMG_DECLARE(app_usb_img);
LV_IMG_DECLARE(app_sd_img);
LV_IMG_DECLARE(app_rf_img);
LV_IMG_DECLARE(app_ir_img);
LV_IMG_DECLARE(app_bluetooth_img);
LV_IMG_DECLARE(app_aplicativos_img);
LV_IMG_DECLARE(app_refazer_img);
LV_IMG_DECLARE(app_desfazer_img);
LV_IMG_DECLARE(desfazer);
LV_IMG_DECLARE(refazer);

LV_FONT_DECLARE(ui_font_symbols16);




bool prompt_is_busy = false;


void prompt_label_timer(lv_timer_t *t)
{
    lv_obj_del((lv_obj_t *)t->user_data);
    lv_timer_del(t);
    prompt_is_busy = false;
}


void prompt_info(char *str, uint16_t time)
{
    if(prompt_is_busy == false){
        lv_obj_t *lable = lv_label_create(lv_layer_top());
        lv_label_set_text(lable, str);
        lv_obj_set_style_bg_opa(lable, LV_OPA_COVER, LV_PART_MAIN);
        lv_obj_set_style_bg_color(lable, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
        lv_obj_center(lable);
        lv_timer_create(prompt_label_timer, time, lable);
        prompt_is_busy = true;
    }
}

void ui_event_wifi(lv_event_t *e)
{
    prompt_info(" Wi-Fi\n nao Implementado", UI_PROMPT_TIME);
}

void ui_event_bt(lv_event_t *e)
{
    prompt_info(" Bluetooth\n nao Implementado", UI_PROMPT_TIME);
}

void ui_event_ir(lv_event_t *e)
{
    prompt_info(" Infra Vermelho\n nao Implementado", UI_PROMPT_TIME);
}

void ui_event_rf(lv_event_t *e)
{
    prompt_info(" Radio\n nao Implementado", UI_PROMPT_TIME);
}

void ui_event_sd(lv_event_t *e)
{
    prompt_info(" Cartao SD\n nao Implementado", UI_PROMPT_TIME);
}

void ui_event_apps(lv_event_t *e)
{
    prompt_info(" Aplicativos\n nao Implementado", UI_PROMPT_TIME);
}

void ui_event_usb(lv_event_t *e)
{
    prompt_info(" USB\n nao Implementado", UI_PROMPT_TIME);
}

void ui_event_config(lv_event_t *e)
{
    /*lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }

    if (event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(ui_setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
    }*/
    
    prompt_info(" Configuracoes\n nao Implementado", UI_PROMPT_TIME);
}

void ui_event_refazer(lv_event_t *e)
{
    prompt_info(" Refazer\n nao Implementado", UI_PROMPT_TIME);
}

void ui_event_desfazer(lv_event_t *e)
{
    prompt_info(" Desfazer\n nao Implementado", UI_PROMPT_TIME);
}


static void backgBut_explain(lv_obj_t *parent, lv_obj_t **obj, char *showData, lv_event_cb_t event_cb, void *event_userData, const void *backg, lv_coord_t x, lv_coord_t y)
{
    int y_skewing = 0;
    lv_obj_t *img_obj = NULL;

    if (backg != NULL) {
        y_skewing = 56;

        if (obj == NULL)
            img_obj = lv_img_create(parent);
        else
            img_obj = *obj = lv_img_create(parent);
        lv_img_set_src(img_obj, backg);
        //lv_obj_set_width(img_obj, 54);
        //lv_obj_set_height(img_obj, 54);
        lv_obj_set_x(img_obj, x);
        lv_obj_set_y(img_obj, y);
        lv_obj_add_flag(img_obj, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);
        lv_obj_clear_flag(img_obj, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                          LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                          LV_OBJ_FLAG_SCROLL_CHAIN);
        if (event_cb != NULL) {
            lv_obj_add_event_cb(img_obj, event_cb, LV_EVENT_PRESSED, (void *)1);
        }
    }

    if (showData != NULL) {
        lv_obj_t *label_obj = lv_label_create(parent);
        lv_obj_set_width(label_obj, 68);
        lv_obj_set_height(label_obj, 54);
        lv_obj_set_x(label_obj, x);
        lv_obj_set_y(label_obj, y + y_skewing);
        if (img_obj != NULL) {
            lv_obj_align_to(label_obj, img_obj, LV_ALIGN_CENTER, 0, 54);
            lv_obj_set_style_text_align(label_obj, LV_TEXT_ALIGN_CENTER, 0);
        } else {
            lv_obj_set_x(label_obj, x);
            lv_obj_set_y(label_obj, y + y_skewing);
        }
        lv_label_set_text(label_obj, showData);
        lv_obj_clear_flag(label_obj, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE |
                          LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);
    }
}


static void electric_quantity_icon_create(lv_obj_t **ui_obj, lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h)
{
    *ui_obj = lv_obj_create(parent);
    lv_obj_set_style_pad_all(*ui_obj, 0, 0);
    lv_obj_set_size(*ui_obj, w + 6, h + 5);
    lv_obj_set_pos(*ui_obj, x, y);
    lv_obj_set_style_bg_opa(*ui_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(*ui_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *border = lv_obj_create(*ui_obj);
    lv_obj_set_style_border_width(border, 2, 0);
    lv_obj_set_style_radius(border, 2, 0);
    lv_obj_clear_flag(border, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(border, w, h);
    lv_obj_set_pos(border, 0, 0);
    lv_obj_set_style_bg_opa(border, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(border, lv_color_hex(0xffffff), 0);
    lv_obj_t *pad = lv_obj_create(*ui_obj);
    lv_obj_set_style_outline_width(pad, 0, 0);
    lv_obj_set_style_outline_pad(pad, 0, 0);
    lv_obj_set_style_border_width(pad, 0, 0);
    lv_obj_set_style_bg_color(pad, lv_color_hex(0xffffff), 0);
    lv_obj_set_size(pad, w - 6, h - 6);
    lv_obj_set_style_border_width(pad, 0, 0);
    lv_obj_set_style_radius(pad, 0, 0);
    lv_obj_align(pad, LV_ALIGN_LEFT_MID, 3, 0);
    lv_obj_clear_flag(pad, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t *line = lv_obj_create(*ui_obj);
    lv_obj_set_style_radius(line, 0, 0);
    lv_obj_set_size(line, 2, h - 6);
    lv_obj_align(line, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_style_border_color(line, lv_color_hex(0xffffff), 0);
}


static void lv_obj_t_create(lv_obj_t **ui_obj, lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h)
{
    *ui_obj = lv_obj_create(parent);
    lv_obj_set_width(*ui_obj, w);
    lv_obj_set_height(*ui_obj, h);
    lv_obj_set_x(*ui_obj, x);
    lv_obj_set_y(*ui_obj, y);
    lv_obj_set_style_pad_all(*ui_obj, 0, 0);
    lv_obj_set_style_radius(*ui_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(*ui_obj, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(*ui_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(*ui_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}


static void ui_label_create(lv_obj_t **ui_label, lv_obj_t *parent, char *showData, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h)
{
    *ui_label = lv_label_create(parent);
    lv_obj_set_width(*ui_label, w);
    lv_obj_set_height(*ui_label, h);
    lv_obj_set_x(*ui_label, x);
    lv_obj_set_y(*ui_label, y);
    lv_label_set_text(*ui_label, showData);
    lv_obj_set_style_text_align(*ui_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_color(*ui_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(*ui_label, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE |
                      LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);
}


void ui_home_create(lv_obj_t **ui_home, lv_obj_t *parent)
{
    *ui_home = lv_obj_create(parent);

    lv_obj_clear_flag(*ui_home, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(*ui_home, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(*ui_home, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(*ui_home, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(*ui_home, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(*ui_home, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(*ui_home, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(*ui_home, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(*ui_home, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(*ui_home, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(*ui_home, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
}


void ui_init()
{
    // Configura a tela com o fundo preto
    lv_obj_t *ui_home = lv_scr_act();
    lv_obj_clear_flag(ui_home, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_pad_all(ui_home, 0, 0);
    lv_obj_set_style_bg_color(ui_home, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(ui_home, LV_OPA_COVER, LV_PART_MAIN);

    lv_obj_t *ui_header = lv_scr_act();
    ui_header = lv_obj_create(ui_home);
    lv_obj_set_style_pad_all(ui_header, 0, 0);
    lv_obj_set_width(ui_header, 10);
    lv_obj_set_height(ui_header, 50);
    lv_obj_set_align(ui_header, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_header, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(ui_header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_header, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_header, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_header, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_body = lv_scr_act();
    ui_body = lv_obj_create(ui_home);
    lv_obj_set_style_pad_all(ui_body, 0, 0);
    lv_obj_set_width(ui_body, SCREEN_WIDTH);
    lv_obj_set_height(ui_body, SCREEN_BODY);
    lv_obj_set_x(ui_body, 0);
    lv_obj_set_y(ui_body, 33);
    lv_obj_set_align(ui_body, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_body, LV_OBJ_FLAG_SCROLL_ONE);
    lv_obj_clear_flag(ui_body, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_scrollbar_mode(ui_body, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_snap_x(ui_body, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scroll_dir(ui_body, LV_DIR_HOR);
    lv_obj_set_style_radius(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_body, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_body, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    lv_obj_t *ui_home1 = lv_scr_act();
    ui_home_create(&ui_home1, ui_body);
    lv_obj_set_width(ui_home1, SCREEN_WIDTH);
    lv_obj_set_height(ui_home1, SCREEN_BODY);
    lv_obj_set_align(ui_home1, LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_bg_color(ui_body, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    backgBut_explain(ui_home1, NULL, (char *)"WIFI", ui_event_wifi, (void *)1, &app_wifi_img, 2, 0);
    backgBut_explain(ui_home1, NULL, (char *)"IR", ui_event_ir, (void *)1, &app_ir_img, 80, 0);
    backgBut_explain(ui_home1, NULL, (char *)"BT", ui_event_bt, (void *)1, &app_bluetooth_img, -2, 90);
    backgBut_explain(ui_home1, NULL, (char *)"RF", ui_event_rf, (void *)1, &app_rf_img, 80, 90);
    backgBut_explain(ui_home1, NULL, (char *)"USB", ui_event_usb, (void *)1, &app_usb_img, -2, 180);
    backgBut_explain(ui_home1, NULL, (char *)"APPs", ui_event_apps, (void *)1, &app_aplicativos_img, 80, 180);
    
    lv_obj_t *ui_home2 = lv_scr_act();
    ui_home_create(&ui_home2, ui_body);
    lv_obj_set_width(ui_home2, SCREEN_WIDTH);
    lv_obj_set_height(ui_home2, SCREEN_BODY);
    lv_obj_set_x(ui_home2, SCREEN_WIDTH);
    lv_obj_set_y(ui_home2, 0);
    lv_obj_set_align(ui_home2, LV_ALIGN_CENTER);
    backgBut_explain(ui_home2, NULL, (char *)"SD", ui_event_sd, (void *)1, &app_sd_img, -2, 0);
    backgBut_explain(ui_home2, NULL, (char *)"Config", ui_event_config, (void *)1, &app_settings_img, 80, 0);
    
  
    lv_obj_t *ui_footer = lv_scr_act();
    ui_footer = lv_obj_create(ui_home);
    lv_obj_set_width(ui_footer, SCREEN_WIDTH);
    lv_obj_set_height(ui_footer, SCREEN_FOOTER);
    lv_obj_set_align(ui_footer, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_footer, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_obj_set_style_radius(ui_footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_footer, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_footer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_footer, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_footer, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    int margin = 15; // Margem a partir da borda direita
    int button_width = 24; // Largura do botão (ajuste conforme necessário)
    int right_x = SCREEN_WIDTH - button_width - margin;

    backgBut_explain(ui_home, NULL, NULL, ui_event_desfazer, (void *)1, &app_desfazer_img, 15, 290);
    backgBut_explain(ui_home, NULL, NULL, ui_event_refazer, (void *)1, &app_refazer_img, right_x, 290);

    lv_obj_t *ui_time = lv_scr_act();
    lv_obj_t *ui_home_electric_quantity_icon = lv_scr_act();
    lv_obj_t *ui_home_electric_quantity_lable = lv_scr_act();
    ui_label_create(&ui_time, ui_home, (char *)"12:12", 0, 7, 60, 30);
    lv_obj_set_align(ui_time, LV_ALIGN_TOP_LEFT);
    electric_quantity_icon_create(&ui_home_electric_quantity_icon, ui_home, 130, 7, 22, 12);

    lv_obj_t *ui_home_wifi_icon = lv_scr_act();
    ui_label_create(&ui_home_wifi_icon, ui_home, (char *)"", 5, 5, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_home_wifi_icon, LV_ALIGN_TOP_MID);
    //lv_obj_add_flag(ui_home_wifi_icon, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_text_font(ui_home_wifi_icon, &ui_font_symbols16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_controlListener = lv_scr_act();
    ui_controlListener = lv_obj_create(ui_home);
    lv_obj_set_style_pad_all(ui_controlListener, 0, 0);
    lv_obj_set_width(ui_controlListener, SCREEN_WIDTH);
    lv_obj_set_height(ui_controlListener, 50);
    lv_obj_set_align(ui_controlListener, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_controlListener, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(ui_controlListener, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_controlListener, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_controlListener, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_controlListener, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_controlCenter = lv_scr_act();
    ui_controlCenter = lv_obj_create(ui_home);
    lv_obj_set_style_pad_all(ui_controlCenter, 0, 0);
    lv_obj_set_width(ui_controlCenter, SCREEN_WIDTH);
    lv_obj_set_height(ui_controlCenter, 320);
    lv_obj_set_x(ui_controlCenter, 0);
    lv_obj_set_y(ui_controlCenter, -320);
    lv_obj_set_align(ui_controlCenter, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_controlCenter, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(ui_controlCenter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_controlCenter, lv_color_hex(0x323232), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_controlCenter, 245, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_Panel10 = NULL;
    lv_obj_t_create(&ui_Panel10, ui_controlCenter, 56, 30, 110, 110);
    lv_obj_set_align(ui_Panel10, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Panel10, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_radius(ui_Panel10, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel10, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel10, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
}


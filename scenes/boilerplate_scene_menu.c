#include "../boilerplate.h"

enum SubmenuIndex {
    SubmenuIndexScene1 = 10,
    SubmenuIndexScene2,
    SubmenuIndexScene3,
    SubmenuIndexScene4,
    SubmenuIndexScene5,
    SubmenuIndexSettings,
};

void boilerplate_scene_menu_submenu_callback(void* context, uint32_t index) {
    Boilerplate* app = context;
    view_dispatcher_send_custom_event(app->view_dispatcher, index);
}

void boilerplate_scene_menu_on_enter(void* context) {
    Boilerplate* app = context;

    canvas_draw_frame(canvas, 2, 2, 124, 60);
    canvas_set_font(canvas, FontSecondary);
    canvas_draw_str(canvas, 48, 13, "Unison")
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 6, 40, "Waiting for instructions")
    canvas_draw_icon(canvas, 57, 45, &I_Nfc_10px)

}

bool boilerplate_scene_menu_on_event(void* context, SceneManagerEvent event) {
    Boilerplate* app = context;
    UNUSED(app);
    if(event.type == SceneManagerEventTypeBack) {
        //exit app
        scene_manager_stop(app->scene_manager);
        view_dispatcher_stop(app->view_dispatcher);
        return true;
    } else if(event.type == SceneManagerEventTypeCustom) {
        if(event.event == SubmenuIndexScene1) {
            scene_manager_set_scene_state(
                app->scene_manager, BoilerplateSceneMenu, SubmenuIndexScene1);
            scene_manager_next_scene(app->scene_manager, BoilerplateSceneScene_1);
            return true;
        } else if (event.event == SubmenuIndexScene2) {
            scene_manager_set_scene_state(
                app->scene_manager, BoilerplateSceneMenu, SubmenuIndexScene2);
            scene_manager_next_scene(app->scene_manager, BoilerplateSceneScene_2);
            return true;
        } else if (event.event == SubmenuIndexScene3) {
            scene_manager_set_scene_state(
                app->scene_manager, BoilerplateSceneMenu, SubmenuIndexScene3);
            scene_manager_next_scene(app->scene_manager, BoilerplateSceneScene_3);
        } else if (event.event == SubmenuIndexSettings) {
            scene_manager_set_scene_state(
                app->scene_manager, BoilerplateSceneMenu, SubmenuIndexSettings);
            scene_manager_next_scene(app->scene_manager, BoilerplateSceneSettings);
            return true;
        }
    }
    return false;
}

void boilerplate_scene_menu_on_exit(void* context) {
    Boilerplate* app = context;
    submenu_reset(app->submenu);
}
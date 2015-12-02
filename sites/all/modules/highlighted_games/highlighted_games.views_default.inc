<?php
/**
 * @file
 * highlighted_games.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function highlighted_games_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'destacados';
  $view->description = 'Lista de Juegos destacados';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Destacados';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Destacados';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Cover */
  $handler->display->display_options['fields']['field_billboard']['id'] = 'field_billboard';
  $handler->display->display_options['fields']['field_billboard']['table'] = 'field_data_field_billboard';
  $handler->display->display_options['fields']['field_billboard']['field'] = 'field_billboard';
  $handler->display->display_options['fields']['field_billboard']['label'] = 'Billboard';
  $handler->display->display_options['fields']['field_billboard']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_billboard']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Favoritos */
  $handler->display->display_options['fields']['field_fivestar']['id'] = 'field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['table'] = 'field_data_field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['field'] = 'field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['label'] = 'Fivestar';
  $handler->display->display_options['fields']['field_fivestar']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_fivestar']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'default',
    ),
    'expose' => 1,
    'style' => 'average',
    'text' => 'average',
  );
  /* Field: Content: Precio US $ */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['label'] = 'Price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Favoritos (field_fivestar:rating) */
  $handler->display->display_options['sorts']['field_fivestar_rating']['id'] = 'field_fivestar_rating';
  $handler->display->display_options['sorts']['field_fivestar_rating']['table'] = 'field_data_field_fivestar';
  $handler->display->display_options['sorts']['field_fivestar_rating']['field'] = 'field_fivestar_rating';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'game' => 'game',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_price' => 'field_price',
    'field_fivestar' => 'field_fivestar',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Favoritos (field_fivestar:target) */
  $handler->display->display_options['sorts']['field_fivestar_target']['id'] = 'field_fivestar_target';
  $handler->display->display_options['sorts']['field_fivestar_target']['table'] = 'field_data_field_fivestar';
  $handler->display->display_options['sorts']['field_fivestar_target']['field'] = 'field_fivestar_target';
  $handler->display->display_options['sorts']['field_fivestar_target']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_fivestar_target']['expose']['label'] = 'Fivestar (field_fivestar:target)';
  /* Sort criterion: Content: Favoritos (field_fivestar:rating) */
  $handler->display->display_options['sorts']['field_fivestar_rating']['id'] = 'field_fivestar_rating';
  $handler->display->display_options['sorts']['field_fivestar_rating']['table'] = 'field_data_field_fivestar';
  $handler->display->display_options['sorts']['field_fivestar_rating']['field'] = 'field_fivestar_rating';
  $handler->display->display_options['sorts']['field_fivestar_rating']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_fivestar_rating']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_fivestar_rating']['expose']['label'] = 'Fivestar (field_fivestar:rating)';
  $handler->display->display_options['block_description'] = 'Destacados';
  $export['destacados'] = $view;

  return $export;
}

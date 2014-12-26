<?
if (!ISSET($form_action) || $form_action=="") {
 include('checkout-list.inc');
} elseif ($form_action=="view") {
 include('checkout-view.inc');
} elseif ($form_action=="update") {
 include('checkout-update.inc');
}
?>

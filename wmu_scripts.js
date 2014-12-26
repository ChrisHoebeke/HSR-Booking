<input type="hidden" id="DPC_TODAY_TEXT" value="today">
<input type="hidden" id="DPC_BUTTON_TITLE" value="Open calendar...">
<input type="hidden" id="DPC_MONTH_NAMES" value="['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']">
<input type="hidden" id="DPC_DAY_NAMES" value="['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat']">
<script language="JavaScript">
  DatePickerControl.onSelect = function(inputid)
  {
    if (inputid == "calendar8"){
      cal8 = document.getElementById("calendar8");
      cal9 = document.getElementById("calendar9");
      cal9.setMinDate(cal8.value);
      cal9.disabled = false;
      setTimeout("document.getElementById('calendar9').focus()", 5);
    }
  }
function toggle() {
	var ele = document.getElementById("toggleText");
	var frm = document.getElementById("toggleForm");
	var text = document.getElementById("displayText");
	if(ele.style.display == "block") {
    		ele.style.display = "none";
    		frm.style.display = "block";
		text.innerHTML = "Add guest";
  	}
	else {
		ele.style.display = "block";
    		frm.style.display = "none";
		text.innerHTML = "Cancel add guest";
	}
} 
</script>

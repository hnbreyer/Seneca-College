function checkAllData()
{
    clearAllErrors();
    var result1=province();
    var result2=street_name();
    var result3=city();
    return result&&result0&&result1&&result2&&result3;
    

}

////////////////////////////////////////////////////////////////
/*function to check whether user selected a province or not*/

function province()
{
   var province=document.signup.province.selectedIndex;
   var error=true;
   var expression=0;
   var error_mess="Please select one of the provinces";
   
   

   if(province==-1)
   {
       
    showerror("<p>"+error_mess+"</p>"); 
    error=false;
   }
  else
  error=true;


   if(!error)
 {
      return false;
 }

 else
 return true;


}


////////////////////////////////////////////////////////////////
/*Function used to check the street name*/

function street_name()
{
  var street=document.signup.street_name.value.trim();
  var alldigits="1234567890";
  var street_error="Street name should not contain any digit";
  var check=0;
  var error=true;

  for(var i=0;i<street.length;i++)
  {
    if(alldigits.indexOf(street.substr(i,1))>=0)
    {
        check=1;
        error=false;
        break;
    }

  }
  
  if(check==1)
  {
    showerror("<p>"+street_error+"</p>");
    error=false;
  }



    if(!error)
     {
       return false;
     }
 
    else
     return true;


}



////////////////////////////////////////////////////////////////

/*Function used to display an error message for the user*/

function showerror(text)
{  
    document.querySelector("#errors").innerHTML+=text;
}
/*Function used to clear all the error messages*/
////////////////////////////////////////////////////////////////
function clearAllErrors()
{
    document.querySelector("#errors").innerHTML="";
}

///////////////////////////////////////////////

function adoptionForm(val){
  var element = document.getElementById('formNumber');
  if (val == 'status'){
    element.style.display='block';
  }else{
    element.style.display = 'none';
  }
}

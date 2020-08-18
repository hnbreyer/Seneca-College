const header = document.getElementById('dataHeader');
const section = document.getElementById('dataSection');


var request;

request = new XMLHttpRequest();
function makeRequest(pageNum) {

    let requestURL = `superheroes${pageNum}.json`;

  
     request.onreadystatechange = showContents;
  
     request.open('GET', requestURL, true);
  
     request.send();
  }

function showContents() {
    //  check for response state
    //  0      The request is not initialized
    //  1      The request has been set up
    //  2      The request has been sent
    //  3      The request is in process
    //  4      The request is complete
    
        if (request.readyState == 4 && request.status == 200) { // The request has succeeded
                // Just for debugging. 
                console.log(request.responseText);
                
                // Javascript function JSON.parse to parse JSON data
                var jsonObj = JSON.parse(request.responseText);
                
             
                populateHeader(jsonObj);
                showHeroes(jsonObj);
    
        } else {
            console.log('There was a problem with the request.');
        }
    }	



request.onload = function() {
  const superHeroes = request.response;
  // document.getElementById('nodata').remove();
}

function populateHeader(jsonObj) {
var headerElement = document.getElementById('dataHeader');

while (headerElement.firstChild){
    headerElement.removeChild(headerElement.firstChild);
}

  const myH1 = document.createElement('h1');
  myH1.textContent = jsonObj['squadName'];

  const myPara = document.createElement('p');
  myPara.textContent = jsonObj['homeTown'];
  
  const moreInfo = document.createComment('h4');
  moreInfo.textContent = jsonObj['formed'];
 
  const fostering = document.createComment('h5');
  moreInfo.textContent = jsonObj['secretBase'];
  
  header.appendChild(myH1);
  header.appendChild(myPara);
  header.appendChild(moreInfo);
  header.appendChild(fostering);
}

function showHeroes(jsonObj) {
    var sectionElement = document.getElementById('dataSection');

    while(sectionElement.firstChild){
        sectionElement.removeChild(sectionElement.firstChild);
    }


  const heroes = jsonObj['info'];

  for(let i = 0; i < heroes.length; i++) {
    const myArticle = document.createElement('card');
    //adding class
    myArticle.classList.add('card');
    const myH2 = document.createElement('h2');
    const myPara1 = document.createElement('p');
    const myPara2 = document.createElement('p');
    const myPara3 = document.createElement('p');
    const myPara4 = document.createElement('p');
    const myList = document.createElement('ul');
    const myAvatar = document.createElement('img');
    myAvatar.classList.add('centerImg');
    const myButton = document.createElement('button');
    myButton.classList.add('adoptButton');

    myH2.textContent = heroes[i].name;
    myPara1.textContent = heroes[i].secretIdentity;
    myPara2.textContent =  heroes[i].age + ' years old';
    myPara3.textContent = heroes[i].gender;
    myPara4.textContent = 'Superpowers:';
    myButton.textContent = 'Adopt me!';

    const superPowers = heroes[i].powers;
    for(let j = 0; j < superPowers.length; j++) {
      const listItem = document.createElement('li');
      listItem.textContent = superPowers[j];
      myList.appendChild(listItem);
    }

    myAvatar.setAttribute('src', heroes[i].image);

    myArticle.appendChild(myH2);
    myArticle.appendChild(myPara1);
    myArticle.appendChild(myPara2);
    myArticle.appendChild(myPara3);
    myArticle.appendChild(myPara4);
    myArticle.appendChild(myList);
    myArticle.appendChild(myAvatar);
    myArticle.appendChild(myButton);

    section.appendChild(myArticle);
  }
}

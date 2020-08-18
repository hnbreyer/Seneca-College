(function() {
  /**
   * Helper object for working with countries data and extracting information.
   * See countries-data.js for format of the countries data set.
   */
  let countries = {
    /**
     * Store all countries from countries-data.js on `countries.all` for convenience.
     */
    all: window.countriesData,
    //const: all = require('./countries-data.js'),
    

    /**
     * Return an array of all countries, with the Name Object replaced by the
     * appropriate translation, or English if not specified (or unknown).  For
     * example, when language="English", you would process the record for Canada into:
     *
     * {
     *     code: "CA",
     *     continent: "Americas",
     *     areaInKm2: 9984670,
     *     population: 36624199,
     *     capital: "Ottawa",
     *     name: "Canada"
     * }
     *
     * Supported languages include:
     *
     * English, Arabic, Chinese, French, Hindi, Korean, Japanese, Russian
     *
     * Uses `countries.all` as the underlying array of countries to be processed.
     *
     * HINT: make sure you don't overwrite the original name object.
     */
    
    getByLanguage: function(language) {
      let arrayLanguage=[];

      countries.all.forEach(function(country){
        let arrLang = {};
        arrLang.code = country.code;
        arrLang.continent = country.continent;
        arrLang.areaInKm2 = country.areaInKm2;
        arrLang.population = country.population;
        arrLang.capital = country.capital;
        arrLang.name = country.name[language];

        arrayLanguage.push(arrLang);

      }
      );
      return arrayLanguage;
    },

    /**
     * Return an array of countries with a population greater than or equal to
     * `minPopulation`, and possibly less than equal to `maxPopulation` (if defined)
     * otherwise allow any number greater than `minPopulation`.
     *
     * Uses getByLanguage('English') to get English names for countries. 
     *
     * @param {Number} minPopulation - (Required) minimum population value
     * @param {Number} maxPopulation - (Optional) maximum population value
     */ 
    getByPopulation: function(minPopulation, maxPopulation) {
      arrayPopulation=[];
      countries.all.forEach(function(country){
        if(country.population >= minPopulation && country.population <= maxPopulation){
          arrayPopulation.push(country);

        }

      
      }
      );
      return arrayPopulation;
    },


    //I was trying the method below at first, but even with JSON.parse and JSON.stringify, it didn't work (I still got 'undefined').
    //With the method above it worked, but I still didn't really understand why it didn't work with the method below.

    /*****for(var i in countries.all){
      if(countries.all[i].population >= minPopulation && countries.all[i].population <= maxPopulation){
          arrayPopulation.push(JSON.parse(JSON.stringify(countries.all[i].population)));
          
        }******/

    /**
     * Return an array of countries for the given `continent` with an area
     * greater than or equal to the given `area` in square KM.
     *
     * Uses getByLanguage('English') to get English names for countries.
     *
     * @param {String} continent - (Required) name of the continent (e.g., Europe)
     * @param {Number} minArea - (Required) minimum number of KM2 area
     */
    getByAreaAndContinent: function(continent, minArea) {
      arrayArea=[];
      countries.all.forEach(function(country){
        if(country.continent === continent && country.areaInKm2 >= minArea){
         
    
            arrayArea.push(country);
          
        }
      }
      );
      return arrayArea;

    }
  };

  /**
   * Helper functions for building table elements.
   */
  let tableHelper = {
    /**
     * Clears (any) existing rows from the #table-rows table body
     */
    clearTable: function() {
      document.querySelector("#table-rows").innerHTML = '';

      // I've trie using the code below (found it in the slides) but it didn't work, so I used innerHtml

      /*****var table = document.querySelector("#table-rows");
      var tblExistingBody = table.querySelector("tbody");
  		if (tblExistingBody) table.removeChild(tblExistingBody);*****/
    },

    /**
     * Takes a `country.code` (e.g., "CA" for Canada) and returns an <img>
     * element with its `src` property set the appropriate flag image URL
     * for this code, e.g., src="flags/ca.png" for Canada.
     * 
     * Note: Some of the images are missing and may result in a 404 error. 
     * Ignore these errors.
     */
    countryCodeToFlagImg: function(countryCode) {
  
      var img = document.createElement("img");
      countries.all.forEach(function(country){
        if(country.code === countryCode){

          img.src = "flags/" + countryCode.toLowerCase() + ".png";
        }

      }
      );
  
      return img;
    },

    /**
     * Takes a single `country` object and converts it to a <tr> with <td>
     * child elements for every column in the row. The row should match the
     * expected format of the table (i.e., flag, code, country, continent, etc).
     * Return the new <tr>...</tr> row.
     *
     * Use the DOM methods document.createElement(), element.appendChild(), etc
     * to create your <tr> row.
     */
    countryToRow: function(country) {
      var row = document.createElement("tr");
      var cell_flag = document.createElement("td");
      var cell_code = document.createElement("td");
      var cell_country = document.createElement("td");
      var cell_cont = document.createElement("td");
      var cell_area = document.createElement("td");
      var cell_pop = document.createElement("td");
      var cell_cap = document.createElement("td");




        cell_flag.appendChild(tableHelper.countryCodeToFlagImg(country.code));
        cell_code.innerText = country.code;
        //if no language is defined, default language is English
        if(typeof country.name === 'object'){
          cell_country.innerText = country.name.English;
        } else{
          cell_country.innerText = country.name;
        }

        cell_cont.innerText = country.continent;
        cell_area.innerText = country.areaInKm2;
        cell_pop.innerText = country.population;
        cell_cap.innerText = country.capital;

        row.appendChild(cell_flag);
        row.appendChild(cell_code);
        row.appendChild(cell_country);
        row.appendChild(cell_cont);
        row.appendChild(cell_area);
        row.appendChild(cell_pop);
        row.appendChild(cell_cap);
   
      
 
      return row;
    },

    /**
     * Takes an array of `country` Objects named `countries`, and passes each
     * `country` in the array  to `tableHelper.countryToRow()`.  The resulting
     * rows are then appended to the #table-rows table body element.  Make sure
     * you use `tableHelper.clear()` to remove any existing rows before you do this.
     */
    countriesToTable: function(countries) {
      tableHelper.clearTable();

      /*****for(var i in countries){
        document.querySelector("#table-rows").appendChild(tableHelper.countryToRow(countries[i]));*****/


        countries.forEach(function(country){
          document.querySelector("#table-rows").appendChild(tableHelper.countryToRow(country));

        }
        //tableHelper.countryToRow(countries[i]);
        );
    }
  };

  /**
   * Register click handlers for every menu item in the page.  Use the `countries`
   * and `tableHelper` Objects, and their associated methods, to update/populate
   * the #table-rows table body with the appropriate set of countries, based on the
   * menu item clicked.
   *
   * Make sure you also update the #subtitle heading to properly reflect what
   * is in the table after you populate it. For example: "List of Countries
   * and Dependencies - Population between 1 and 2 million" or "List of Countries
   * and Dependencies - All countries in Asia" etc.
   */
  function setupMenuHandlers() {
    //English
    var menuEnglish = document.querySelector("#menu_english");
    
    menuEnglish.onclick = function(){
      document.querySelector("#subtitle").innerText = 'List of Countries and Dependencies';
      tableHelper.countriesToTable(countries.getByLanguage('English'));
    };
    //Arabic
    var menuArabic = document.querySelector("#menu_arabic");
   
    menuArabic.onclick = function(){
      document.querySelector("#subtitle").innerText = 'List of Countries and Dependencies - names in Arabic';
      tableHelper.countriesToTable(countries.getByLanguage('Arabic'));
    };
    //Chinese
    var menuChinese = document.querySelector("#menu_chinese");
   
    menuChinese.onclick = function(){
      document.querySelector("#subtitle").innerText = 'List of Countries and Dependencies - names in 中文 (Chinese)';
      tableHelper.countriesToTable(countries.getByLanguage('Chinese'));
    };
    //French
    var menuFrench = document.querySelector("#menu_french");
   
    menuFrench.onclick = function(){
      document.querySelector("#subtitle").innerText = 'List of Countries and Dependencies - names in French';
      tableHelper.countriesToTable(countries.getByLanguage('French'));
    };
    //Hindi
    var menuHindi = document.querySelector("#menu_hindi");
   
    menuHindi.onclick = function(){
      document.querySelector("#subtitle").innerText = 'List of Countries and Dependencies - names in Hindi';
      tableHelper.countriesToTable(countries.getByLanguage('Hindi'));
    };
    //Korean
    var menuKorean = document.querySelector("#menu_korean");
   
    menuKorean.onclick = function(){
      document.querySelector("#subtitle").innerText = 'List of Countries and Dependencies - names in Korean';
      tableHelper.countriesToTable(countries.getByLanguage('Korean'));
    };
    //Japanese
    var menuJapanese = document.querySelector("#menu_japanese");
   
    menuJapanese.onclick = function(){
      document.querySelector("#subtitle").innerText = 'List of Countries and Dependencies - names in Japanese';
      tableHelper.countriesToTable(countries.getByLanguage('Japanese'));
    };
    //Russian
    var menuRussian = document.querySelector("#menu_russian");
   
    menuRussian.onclick = function(){
      document.querySelector("#subtitle").innerText = 'List of Countries and Dependencies - names in Russian';
      tableHelper.countriesToTable(countries.getByLanguage('Russian'));
    };

    //Population
    ////100,000,000
    document.querySelector('#menu_population_100_000_000m').onclick = function() {
      document.querySelector('#subtitle').innerText =
          'List of Countries and Dependencies with population greater than 100,000,000';
          tableHelper.countriesToTable(countries.getByPopulation(100000001, 999999999));
    };
    ////1~2 million
    document.querySelector("#menu_population_1m_2m").onclick = function() {
      document.querySelector("#subtitle").innerText =
        'List of Countries and Dependencies with population between 1 ~ 2 million';
      tableHelper.countriesToTable(countries.getByPopulation(1000000, 2000000));
  };
  //Area and continent
  ////1Mkm, Americas
  document.querySelector("#menu_americas_1mkm").onclick = function() {
    document.querySelector("#subtitle").innerText =
          'List of Countries with area greater than 1 million Km2 located in the Americas ';
        tableHelper.countriesToTable(countries.getByAreaAndContinent('Americas', 1000000));
  };
  ////All sizes, Asia
  document.querySelector("#menu_asia_all").onclick = function() {
    document.querySelector("#subtitle").innerText =
          'List of Countries in Asia';
        tableHelper.countriesToTable(countries.getByAreaAndContinent('Asia', 0));
};
  }

  // When the page loads, setup all event handlers by calling setup function.
  window.onload = setupMenuHandlers;
})();

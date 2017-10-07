  var fs = require('fs');
  
  var firebase = require('firebase');
  // Initialize Firebase
  var config = {
    apiKey: "<your apiKey>",
    authDomain: "<your authDomain>",
    databaseURL: "<your databaseURL>",
    projectId: "<your project id>",
    storageBucket: "<your storageBucket>",
    messagingSenderId: "<your messagingSenderId>"
  };
  firebase.initializeApp(config);
  var database = firebase.database();
  var ref = database.ref('auth');

//reading file
var email = fs.readFileSync('./stuff/demo.txt', 'utf8');
var psw = fs.readFileSync('./stuff/demo2.txt', 'utf8');
var authen = firebase.auth();
//sign in
var promise = authen.signInWithEmailAndPassword(email, psw);
promise
.then(user => console.log(user.message))
.catch(e => console.log(e.message));

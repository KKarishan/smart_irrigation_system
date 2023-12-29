// firebase.auth().onAuthStateChanged(function(user) {
//     if (user) {
//         // User is signed in.

//         // $(".login-cover").hide();
//         // window.alert("Error : ");
//         // document.getElementById("loginForm").style.display = "index.html";
//         // document.getElementById("index.html").style.display = "block";
//         window.location = "index.html"; // working here

//     } else {
//         // No user is signed in.
//         // $(".loginForm").show();
//         // document.getElementById("loginForm").style.display = "block";
//         // document.getElementById("index.html").style.display = "none";
//         // window.location = "index.html";
//         // window.alert("Error : ");

//     }
// });



// var user = firebase.auth().currentUser;

// if (user) {
//     // User is signed in.
//     // window.alert("Error : signed in.");
//     // window.location = "index.html";

// } else {
//     // No user is signed in.
//     // window.alert("Error : not signed in.");
// window.location = "index.html";  // working here

// }





// FIRST ERROR AND THEN ONLY CHECK EVERYTHING

// function login() {
//     var userEmail = document.getElementById("emailid").value;
//     var userPassword = document.getElementById("passwordid").value;

//     // window.alert("Error : ");
//     firebase.auth().signInWithEmailAndPassword(userEmail, userPassword).catch(function(error) {

//         // Handle Errors here.
//         var errorCode = error.code;
//         var errorMessage = error.message;
//         window.alert("Error : " + errorMessage);

//         firebase.auth().onAuthStateChanged(function(user) {
//             if (user) {
//                 // User is signed in.

//                 // window.location = "login.html".hide; //with & without working
//                 window.location = "index.html"; // working here

//             } else {
//                 // No user is signed in.

//             }
//         });

//         // ...
//     });


// }




// CORRECT USER LOGING PAGE DEVELOPED IN HERE

function login() {
    var userEmail = document.getElementById("emailid").value;
    var userPassword = document.getElementById("passwordid").value;

    firebase.auth().onAuthStateChanged(function(user) {
        if (user) {
            // User is signed in.

            // window.location = "login.html".hide; //with & without working
            window.location = "index.html"; // working here

        } else {
            // No user is signed in.
            firebase.auth().signInWithEmailAndPassword(userEmail, userPassword).catch(function(error) {

                // Handle Errors here.
                var errorCode = error.code;
                var errorMessage = error.message;
                window.alert("Error : " + errorMessage);
                // ...
            });
        }
    });

}

function logout() {

    firebase.auth().signOut().then(function() {
        // Sign-out successful.
        window.location = "login.html";
    }).catch(function(error) {
        // An error happened.
        window.alert(error.message);
    });

}